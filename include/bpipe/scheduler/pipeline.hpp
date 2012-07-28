/*
 * pipeline.hpp
 *
 *  Created on: Jul 28, 2012
 *      Author: blackpanth3r
 */

#ifndef BPIPE_SCHEDULER_PIPELINE_HPP
#define BPIPE_SCHEDULER_PIPELINE_HPP

#include "bpipe/config.hpp"

#include <memory>
#include <vector>
#include <deque>

namespace bpipe {
	class Step;
	class ParameterDatabase;
}  // namespace bpipe

namespace bpipe {

	BPIPE_API_ENTRY
	std::deque<std::shared_ptr<Step>> buildStepExecutionQueue( const ParameterDatabase& inputs, const std::vector<std::shared_ptr<Step>>& );

}  // namespace bpipe


#endif /* BPIPE_SCHEDULER_PIPELINE_HPP */
