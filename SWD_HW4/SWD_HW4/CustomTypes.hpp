/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: Contains all custom made types
/// --------------------------------------------------------

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>
#include <math.h>
#include <iostream>

#define IN 
#define OUT 
#define IN_OUT 

namespace istvan_richard
{
    class DailyDateTime
    {
    public:
        //Default C'Tor
        DailyDateTime() :
            m_Day_s("ALL"),
            m_NumOfDay_i32(10),
            m_Hour_i32(12),
            m_Minutes_i32(12),
            m_Seconds_i32(12)
        {}
        //Setter, param C'Tor
        DailyDateTime(std::string f_day_s, int f_hour_i32, int f_minutes_i32, int f_seconds_i32) :
            m_Day_s(f_day_s),
            m_NumOfDay_i32(0),
            m_Hour_i32(f_hour_i32),
            m_Minutes_i32(f_minutes_i32),
            m_Seconds_i32(f_seconds_i32)
        {
            if ("MONDAY" == m_Day_s)
            {
                m_NumOfDay_i32 = 1;
            }
            else if ("TUESDAY" == m_Day_s)
            {
                m_NumOfDay_i32 = 2;
            }
            else if ("WEDNESDAY" == m_Day_s)
            {
                m_NumOfDay_i32 = 3;
            }
            else if ("THURSDAY" == m_Day_s)
            {
                m_NumOfDay_i32 = 4;
            }
            else if ("FRYDAY" == m_Day_s)
            {
                m_NumOfDay_i32 = 5;
            }
            else if ("SATURDAY" == m_Day_s)
            {
                m_NumOfDay_i32 = 6;
            }
            else if ("SUNDAY" == m_Day_s)
            {
                m_NumOfDay_i32 = 7;
            }
            else if ("ALL" == m_Day_s)
            {
                m_NumOfDay_i32 = 10;
            }
            else
            {
                m_NumOfDay_i32 = 0;
                std::cout<<"Error Occured, Wrong Name for Day, name is: "<< m_Day_s << "Corresponding hours: "<< m_Hour_i32 << std::endl;
            }
        }
        //Copy C'tor
        DailyDateTime(const DailyDateTime& f__r):
            m_Day_s("ALL"),
            m_NumOfDay_i32(10),
            m_Hour_i32(12),
            m_Minutes_i32(12),
            m_Seconds_i32(12)
        {
            if (this != &f__r)
            {
                this->m_Day_s = f__r.m_Day_s;
                this->m_Hour_i32 = f__r.m_Hour_i32;
                this->m_Minutes_i32 = f__r.m_Minutes_i32;
                this->m_Seconds_i32 = f__r.m_Seconds_i32;
                this->m_NumOfDay_i32 = f__r.m_NumOfDay_i32;
            }
        }

        /// Take care, this function disregards potential differnces in days!! Only valid for same-day compare!
        bool operator < (const DailyDateTime& f_refTime)
        {
            if (this->fGetHour() < f_refTime.fGetHour())
            {
                //hour is lower than ref, definetly earlier time. If hours are equal, then check minutes
                return true;
            }
            else if (this->fGetHour() == f_refTime.fGetHour())
            {
                if (this->fGetMinute() < f_refTime.fGetMinute())
                {
                    //Same hour, lower minute, thus earlier point in time
                    return true;
                }
                else if (this->fGetMinute() == f_refTime.fGetMinute())
                {
                    //same hour, same minute
                    if (this->fGetSec() < f_refTime.fGetSec())
                    {
                        //Same hour, same minute, lower sec thus earlier point in time
                        return true;
                    }
                }
            }
            //Not returned anywhere above. Thus time is equal or lower.
            return false;
        }

        bool operator <= (const DailyDateTime& f_refTime)
        {
            if (this->fGetHour() < f_refTime.fGetHour())
            {
                //hour is lower than ref, definetly earlier time. If hours are equal, then check minutes
                return true;
            }
            else if (this->fGetHour() == f_refTime.fGetHour())
            {
                if (this->fGetMinute() < f_refTime.fGetMinute())
                {
                    //Same hour, lower minute, thus earlier point in time
                    return true;
                }
                else if (this->fGetMinute() == f_refTime.fGetMinute())
                {
                    //same hour, same minute
                    if (this->fGetSec() <= f_refTime.fGetSec())
                    {
                        //Same hour, same minute, lower sec thus earlier point in time
                        return true;
                    }
                }
            }
            //Not returned anywhere above. Thus time is equal or lower.
            return false;
        }

        bool operator >= (const DailyDateTime& f_refTime)
        {
            if (this->fGetHour() > f_refTime.fGetHour())
            {
                //hour is higher than ref, definetly later time. If hours are equal, then check minutes
                return true;
            }
            else if (this->fGetHour() == f_refTime.fGetHour())
            {
                if (this->fGetMinute() > f_refTime.fGetMinute())
                {
                    //Same hour, higher minute, thus later point in time
                    return true;
                }
                else if (this->fGetMinute() == f_refTime.fGetMinute())
                {
                    //same hour, same minute
                    if (this->fGetSec() >= f_refTime.fGetSec())
                    {
                        //Same hour, same minute, higher sec thus later point in time
                        return true;
                    }
                }
            }
            //Not returned anywhere above. Thus time is equal or lower.
            return false;
        }

        bool operator > (const DailyDateTime& f_refTime)
        {
            if (this->fGetHour() > f_refTime.fGetHour())
            {
                //hour is higher than ref, definetly later time. If hours are equal, then check minutes
                return true;
            }
            else if (this->fGetHour() == f_refTime.fGetHour())
            {
                if (this->fGetMinute() > f_refTime.fGetMinute())
                {
                    //Same hour, higher minute, thus later point in time
                    return true;
                }
                else if (this->fGetMinute() == f_refTime.fGetMinute())
                {
                    //same hour, same minute
                    if (this->fGetSec() > f_refTime.fGetSec())
                    {
                        //Same hour, same minute, higher sec thus later point in time
                        return true;
                    }
                }
            }
            //Not returned anywhere above. Thus time is equal or lower.
            return false;
        }

        const std::string fGetDay() const
        {
            return this->m_Day_s;
        }
        const int fGetNumOfDay() const
        {
            return this->m_NumOfDay_i32;
        }
        const int fGetHour() const
        {
            return this->m_Hour_i32;
        }
        const int fGetMinute() const
        {
            return this->m_Minutes_i32;
        }
        const int fGetSec() const
        {
            return this->m_Seconds_i32;
        }

    private:
        std::string m_Day_s;
        int m_NumOfDay_i32;
        int m_Hour_i32;
        int m_Minutes_i32;
        int m_Seconds_i32;
    };

    class TimeStamp
    {
    public:
        //C'Tor
       TimeStamp():
           m_CurrentTime(std::string("MONDAY"), 0, 0, 1)
       {}
       void fUpdateCurrentTime(const DailyDateTime& f_CurrTimeInfo_r)
       {
           m_CurrentTime = f_CurrTimeInfo_r;
       }
       DailyDateTime fGetCurrentTime()
       {
           return m_CurrentTime;
       }
    private:
        DailyDateTime m_CurrentTime;

    };

    class DateTime
    {
    public:
        //default C'tor
        DateTime():
            m_Days_adt()
        {
            m_Days_adt.push_back(DailyDateTime(std::string("ALL"), 12, 0, 0));
        }
        //Param C'tors
        DateTime(DailyDateTime &f_DateTime_r) :
            m_Days_adt()
        {
            m_Days_adt.push_back(f_DateTime_r);
        }
        DateTime(DailyDateTime& f_DateTime_r1, DailyDateTime& f_DateTime_r2) :
            m_Days_adt()
        {
            m_Days_adt.push_back(f_DateTime_r1);
            m_Days_adt.push_back(f_DateTime_r2);
        }
        DateTime(DailyDateTime& f_DateTime_r1, DailyDateTime& f_DateTime_r2, DailyDateTime& f_DateTime_r3) :
            m_Days_adt()
        {
            m_Days_adt.push_back(f_DateTime_r1);
            m_Days_adt.push_back(f_DateTime_r2);
            m_Days_adt.push_back(f_DateTime_r3);
        }
        DateTime(DailyDateTime& f_DateTime_r1, DailyDateTime& f_DateTime_r2, DailyDateTime& f_DateTime_r3,
            DailyDateTime& f_DateTime_r4) :
            m_Days_adt()
        {
            m_Days_adt.push_back(f_DateTime_r1);
            m_Days_adt.push_back(f_DateTime_r2);
            m_Days_adt.push_back(f_DateTime_r3);
            m_Days_adt.push_back(f_DateTime_r4);
        }
        DateTime(DailyDateTime& f_DateTime_r1, DailyDateTime& f_DateTime_r2, DailyDateTime& f_DateTime_r3,
            DailyDateTime& f_DateTime_r4, DailyDateTime& f_DateTime_r5) :
            m_Days_adt()
        {
            m_Days_adt.push_back(f_DateTime_r1);
            m_Days_adt.push_back(f_DateTime_r2);
            m_Days_adt.push_back(f_DateTime_r3);
            m_Days_adt.push_back(f_DateTime_r4);
            m_Days_adt.push_back(f_DateTime_r5);
        }
        DateTime(DailyDateTime& f_DateTime_r1, DailyDateTime& f_DateTime_r2, DailyDateTime& f_DateTime_r3,
            DailyDateTime& f_DateTime_r4, DailyDateTime& f_DateTime_r5, DailyDateTime& f_DateTime_r6) :
            m_Days_adt()
        {
            m_Days_adt.push_back(f_DateTime_r1);
            m_Days_adt.push_back(f_DateTime_r2);
            m_Days_adt.push_back(f_DateTime_r3);
            m_Days_adt.push_back(f_DateTime_r4);
            m_Days_adt.push_back(f_DateTime_r5);
            m_Days_adt.push_back(f_DateTime_r6);
        }
        DateTime(DailyDateTime& f_DateTime_r1, DailyDateTime& f_DateTime_r2, DailyDateTime& f_DateTime_r3,
            DailyDateTime& f_DateTime_r4, DailyDateTime& f_DateTime_r5, DailyDateTime& f_DateTime_r6,
            DailyDateTime& f_DateTime_r7) :
            m_Days_adt()
        {
            m_Days_adt.push_back(f_DateTime_r1);
            m_Days_adt.push_back(f_DateTime_r2);
            m_Days_adt.push_back(f_DateTime_r3);
            m_Days_adt.push_back(f_DateTime_r4);
            m_Days_adt.push_back(f_DateTime_r5);
            m_Days_adt.push_back(f_DateTime_r6);
            m_Days_adt.push_back(f_DateTime_r7);
        }
        //Copy C'Tor
        DateTime(const DateTime& f__r):
            m_Days_adt()
        {
            if (this != &f__r)
            {
                this->m_Days_adt = f__r.m_Days_adt;
            }
        }

        std::vector<DailyDateTime>::iterator fGetDaysVectorBeginning()
        {
            return m_Days_adt.begin();
        }

        std::vector<DailyDateTime>::iterator fGetDaysVectorEnd()
        {
            return m_Days_adt.end();
        }

        std::vector<DailyDateTime> fGetDaysVector()
        {
            return this->m_Days_adt;
        }

        DailyDateTime fGetCurrentDaySetup(TimeStamp& f_TimeStamp_r)
        {
            std::string l_currentDay_s = f_TimeStamp_r.fGetCurrentTime().fGetDay();
            for (auto l_it_p = this->m_Days_adt.begin();
                l_it_p != this->m_Days_adt.end();
                l_it_p++)
            {
                std::string l_refDay_s = l_it_p->fGetDay();
                if (l_refDay_s == l_currentDay_s || "ALL" == l_refDay_s)
                {
                    return *l_it_p;
                }
            }
            DailyDateTime l_ret(std::string("ERROR_MATCH_FINDING_GETCURRENTDAY."), 0, 0, 0);
            return l_ret;
            std::printf("NoMatchingDaysInArray");
        }

        int fGetTimeInSecToRef_sameDay(TimeStamp l_currentTime)
        {
            auto l_refDay(fGetCurrentDaySetup(l_currentTime));
            int l_ret_i32(0);
            l_ret_i32 += 60 * 60 * (l_refDay.fGetHour() - l_currentTime.fGetCurrentTime().fGetHour());
            l_ret_i32 += 60 * (l_refDay.fGetMinute() - l_currentTime.fGetCurrentTime().fGetMinute());
            l_ret_i32 += (l_refDay.fGetSec() - l_currentTime.fGetCurrentTime().fGetSec());
            return l_ret_i32;
        }

        int fGetTimeInSecSinceRef_sameDay(TimeStamp l_currentTime)
        {
            auto l_refDay(fGetCurrentDaySetup(l_currentTime));
            int l_ret_i32(0);
            l_ret_i32 += 60 * 60 * (l_currentTime.fGetCurrentTime().fGetHour() - l_refDay.fGetHour());
            l_ret_i32 += 60 * (l_currentTime.fGetCurrentTime().fGetMinute() - l_refDay.fGetMinute() );
            l_ret_i32 += (l_currentTime.fGetCurrentTime().fGetSec() - l_refDay.fGetSec());
            return l_ret_i32;
        }

        int fGetTimeDiffSinceRefInSec(const DailyDateTime f_refStamp, const TimeStamp f_currentTime)
        {
            auto l_currTime(f_currentTime);
            auto l_refStamp(f_refStamp);
            int l_ret_i32(0);
            l_ret_i32 += 60 * 60 * abs(l_currTime.fGetCurrentTime().fGetHour() - l_refStamp.fGetHour());
            l_ret_i32 += 60 * abs(l_currTime.fGetCurrentTime().fGetMinute() - l_refStamp.fGetMinute());
            l_ret_i32 += abs(l_currTime.fGetCurrentTime().fGetSec() - l_refStamp.fGetSec());
            return l_ret_i32;
        }

    private:
        std::vector<DailyDateTime> m_Days_adt;
    };

    
}//end of namespace

#endif