/*
 * scheduler.h
 *
 *  Created on: Jul 28, 2012
 *      Author: blackpanth3r
 */

#ifndef BPIPE_SCHEDULER_SCHEDULER_HPP
#define BPIPE_SCHEDULER_SCHEDULER_HPP

#include "bpipe/config.hpp"

#include <memory>
#include <string>
#include <vector>
#include <map>

namespace bpipe {
	class Step;
	class ParameterDatabase;
	struct ExecutionResult;
}  // namespace bpipe

namespace bpipe {

	class Scheduler
	{
	public:
		typedef std::shared_ptr<Step>                 SharedPointerStep;
		typedef std::vector<SharedPointerStep>        CollectionSharedPointerStep;

		typedef std::map<std::string,ExecutionResult> StepExecutionResults;

		BPIPE_API_ENTRY
		explicit Scheduler( );

		BPIPE_API_ENTRY
		StepExecutionResults executeSynchronous(
				const CollectionSharedPointerStep&,
				ParameterDatabase&                 inputs);
	private:
		class ExecutionJob
		{
		public:
			explicit ExecutionJob(
					Scheduler&            parent,
					ParameterDatabase&    inputs,
					const Step&           step,
					StepExecutionResults& execution_results );

			void run( ) const;
		private:
			Scheduler&            mParent;
			ParameterDatabase&    mInputs;
			const Step&           mStep;
			StepExecutionResults& mResults;
		};

		void queueJob( const ExecutionJob& );
	};

} /* namespace bpipe */

#endif /* BPIPE_SCHEDULER_SCHEDULER_HPP */
