/*
 * DBReader.h
 *
 *  Created on: 2012-06-13
 *      Author: mathieu
 */

#ifndef DBREADER_H_
#define DBREADER_H_

#include "rtabmap/core/RtabmapExp.h" // DLL export/import defines

#include <utilite/UThreadNode.h>
#include <utilite/UTimer.h>

#include <opencv2/core/core.hpp>

#include <set>

namespace rtabmap {

class DBDriver;

class RTABMAP_EXP DBReader : public UThreadNode {
public:
	DBReader(const std::string & databasePath,
			 float frameRate = 0.0f);
	virtual ~DBReader();

	bool init(int startIndex=0);
	void setFrameRate(float frameRate);
	void getNextImage(cv::Mat & sensors);

protected:
	virtual void mainLoopBegin();
	virtual void mainLoop();

private:
	std::string _path;
	float _frameRate;

	DBDriver * _dbDriver;
	UTimer _timer;
	std::set<int> _ids;
	std::set<int>::iterator _currentId;
};

} /* namespace rtabmap */
#endif /* DBREADER_H_ */