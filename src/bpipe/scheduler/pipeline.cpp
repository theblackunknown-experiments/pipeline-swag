/*
 * pipeline.cpp
 *
 *  Created on: Jul 28, 2012
 *      Author: blackpanth3r
 */

#include "bpipe/scheduler/pipeline.hpp"

#include <string>
#include <list>
#include <set>
#include <iterator>

#include "bpipe/parameter/parameter_description.hpp"
#include "bpipe/parameter/parameter_database.hpp"
#include "bpipe/step/step.hpp"

namespace bpipe {
	namespace {
		struct ParameterDescriptionEquivalence
		{
			bool operator()(const ParameterDescription& lhs, const ParameterDescription& rhs) const
			{
				return lhs.identifier < rhs.identifier
					&& rhs.identifier < lhs.identifier
					&& lhs.type       < rhs.type
					&& rhs.type       < lhs.type;

			}
		};

		bool fetchReadySteps(
				const std::set<ParameterDescription, ParameterDescriptionEquivalence>& available_data,
				std::vector<std::shared_ptr<Step>>&                                    remaining_steps,
				std::vector<std::shared_ptr<Step>>&                                    ready_steps )
		{
			ready_steps.clear( );
			for(auto pstep : remaining_steps)
			{
				if( pstep )
				{
					auto       expected_inputs     = pstep->getExpectedInputs( );
					const auto set_expected_inputs = std::set<ParameterDescription, ParameterDescriptionEquivalence>( expected_inputs.begin(), expected_inputs.end() );
					auto is_empty = set_expected_inputs.empty();
					auto required_inputs_are_present = std::includes(available_data.begin(), available_data.end(), expected_inputs.begin(), expected_inputs.end(), ParameterDescriptionEquivalence());
					if( is_empty || required_inputs_are_present )
					{
						ready_steps.push_back( pstep );
					}
				}
			}

			for(auto pstep : ready_steps)
			{
				auto finder = std::find( remaining_steps.begin(), remaining_steps.end(), pstep );
				if( finder != remaining_steps.end() )
				{
					remaining_steps.erase( finder );
				}
			}

			return !ready_steps.empty();
		}

	}  // namespace

std::deque<std::shared_ptr<Step>> buildStepExecutionQueue(
		const ParameterDatabase& inputs,
		const std::vector<std::shared_ptr<Step>>& steps )
{
	std::deque<std::shared_ptr<Step>> ordered_steps_scheduling;

	//NOTE: We identify available input data only with identifier and not with types checking
	auto initial_inputs_descriptions = inputs.getParametersDescription( );
	std::set<ParameterDescription, ParameterDescriptionEquivalence> availables_inputs_pool( initial_inputs_descriptions.begin(), initial_inputs_descriptions.end() );

	std::vector<std::shared_ptr<Step>>   remaining_steps( steps.begin(), steps.end() );
	std::vector<std::shared_ptr<Step>> ready_steps;
	while( fetchReadySteps( availables_inputs_pool, remaining_steps, ready_steps ) )
	{
		for(auto pstep : ready_steps)
		{
			if( pstep )
			{
				auto expected_outputs = pstep->getExpectedOutputs( );
				availables_inputs_pool.insert( expected_outputs.begin(), expected_outputs.end() );
				ordered_steps_scheduling.push_back( pstep );
			}
		}
	}

	return ordered_steps_scheduling;
}

}  // namespace bpipe


