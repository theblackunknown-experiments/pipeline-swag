/*
 * scheduler.cpp
 *
 *  Created on: Jul 28, 2012
 *      Author: blackpanth3r
 */

#include "bpipe/scheduler/scheduler.hpp"

#include <algorithm>
#include <iterator>

#include "bpipe/parameter/parameter_database.hpp"

#include "bpipe/scheduler/pipeline.hpp"
#include "bpipe/scheduler/result.hpp"

#include "bpipe/step/step.hpp"

namespace bpipe {

Scheduler::Scheduler() {

}

Scheduler::StepExecutionResults Scheduler::executeSynchronous(
		const CollectionSharedPointerStep& steps,
		ParameterDatabase&                 inputs)
{
	//build a dependency graphs to know which step are independent
	std::deque<std::shared_ptr<Step>> step_execution_queue  = buildStepExecutionQueue( inputs, steps );
	//Prepare a container to store execution results
	StepExecutionResults results;

	{
		Scheduler& that = *this;
		//std::for_each(step_execution_queue.begin(), step_execution_queue.end(),
		//		[&that, &inputs, &results](const SharedPointerStep& pstep)
		//		{
		//			if( pstep.get( ) != nullptr )
		//			{
		//				ExecutionJob job( that, inputs, *pstep, results );
		//				job.run( );
		//			}
		//		}
		//);
		for(auto step : step_execution_queue)
		{
			if( step.get( ) != nullptr )
			{
				ExecutionJob job( that, inputs, *step, results );
				job.run( );
			}
		}
	}

	////TODO: As a test we make every step fail w/o executing them
	//ExecutionResult failed = { false };
	//std::transform(steps.begin(), steps.end(), std::inserter(results, results.begin()),
	//		[&failed](const CollectionSharedPointerStep::value_type& pstep)
	//		{
	//			return std::make_pair(pstep->getDescription( ), failed);
	//		}
	//);

	return results;
}

Scheduler::ExecutionJob::ExecutionJob(
		Scheduler&            parent,
		ParameterDatabase&    inputs,
		const Step&           step,
		StepExecutionResults& execution_results )
	: mParent  ( parent )
	, mInputs  ( inputs )
	, mStep    ( step )
	, mResults ( execution_results )
{

}

void Scheduler::ExecutionJob::run( ) const
{
	ParameterDatabase outputs;
	const bool      success           = mStep(mInputs, outputs);
	if( success )
	{
		mInputs.insert( outputs );
	}
	ExecutionResult execution_result  = { success };
	mResults.insert( std::make_pair(mStep.getDescription(), execution_result) );
}

} /* namespace bpipe */
