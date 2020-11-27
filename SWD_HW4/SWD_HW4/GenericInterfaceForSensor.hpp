#pragma once

#ifndef GENERIC_INTERFACE_FOR_MOTIONSENSOR_HPP
#define GENERIC_INTERFACE_FOR_MOTIONSENSOR_HPP

namespace istvan_richard
{
	class CGenericMotionSensorInterface
	{
	public:
		float fGetResolution();
		float fGetMinRange();
		float fGetMaxRange();
		float fGetSamplingRate();
	private:
		std::string     m_SensorType_s;
		float           m_Resolution_f64;
		float           m_MinRange_f64;
		float           m_MaxRange_f64;
		float           m_SamplingRate_f64;

		
	};


}//end of namespace

#endif