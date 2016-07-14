/*
 * DevsJobsOffline.h
 *
 *  Created on: 14/07/2016
 *      Author: jlrisco
 */

#ifndef SRC_XDEVS_DEVSJOBSOFFLINE_H_
#define SRC_XDEVS_DEVSJOBSOFFLINE_H_

#include <xdevs/core/modeling/Port.h>
#include <xdevs/core/modeling/Atomic.h>
#include <xdevs/core/modeling/Event.h>

class DevsJobsOffline : public Atomic {
public:
	typedef struct {
		long second;
		double tempIncrement;
	} JobEntry;

	Port iStop;
	Port oOut;
	DevsJobsOffline(const std::string& name, const std::string& jobsFilePath);
	virtual ~DevsJobsOffline();

	// DEVS protocol
	virtual void initialize();
	virtual void exit();
	virtual void deltint();
	virtual void deltext(double e);
	virtual void lambda();
protected:
	std::ifstream jobsFile;
	JobEntry* nextJobEntry;
	JobEntry* getNextEntry();
};

#endif /* SRC_XDEVS_DEVSJOBSOFFLINE_H_ */
