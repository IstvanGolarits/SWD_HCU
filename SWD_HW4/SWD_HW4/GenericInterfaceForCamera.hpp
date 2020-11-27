#pragma once


#ifndef GENERIC_INTERFACE_FOR_CAMERASENSOR_HPP
#define GENERIC_INTERFACE_FOR_CAMERASENSOR_HPP

namespace istvan_richard
{
	class CGenericCameraSensorInterface
	{
	public:
		float fGetResolution();
		float fGetMinRange();
		float fGetMaxRange();
		float fFPSGetSamplingRate();
	private:
		std::string     m_SensorType_s;
		float           m_Resolution_f64;
		float           m_MinRange_f64;
		float           m_MaxRange_f64;
		float           m_FPSSamplingRate_f64;

	};


}//end of namespace

#endif