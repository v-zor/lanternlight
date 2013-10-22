/*
 * linetype.h
 *
 *  Created on: Oct 22, 2013
 *      Author: bubble
 */

#ifndef LINETYPE_H_
#define LINETYPE_H_

namespace lanternlight
{

class LineType
{
	public:
		LineType();
		virtual ~LineType();

	typedef enum LINETYPE { QUADRANT1LINE = 100, QUADRANT2LINE = 200, QUADRANT3LINE = 300, QUADRANT4LINE = 400, NOLINE = 500,} LINETYPE;


	LINETYPE operator()() { return _id; }
	void set(LINETYPE lt) { _id = lt; }

	protected:
		LINETYPE _id;
};

}//namespace lanternlight
#endif /* LINETYPE_H_ */
