#include <cassert>

#include "Date.h"
#include "../Utilities/Debug.h"

const int Date::INITIAL_YEAR = 389;
const int Date::MONTHS_PER_YEAR = 12;
const int Date::DAYS_PER_MONTH = 30;
const int Date::DAYS_PER_WEEK = 7;

Date::Date(int year, int month, int day)
{
	// Make sure each value is in a valid range.
	assert(year >= 1);
	assert(month >= 0);
	assert(month < Date::MONTHS_PER_YEAR);
	assert(day >= 0);
	assert(day < Date::DAYS_PER_MONTH);

	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(int month, int day)
	: Date(Date::INITIAL_YEAR, month, day) { }

Date::Date()
	: Date(Date::INITIAL_YEAR, 0, 0) { }

int Date::getYear() const
{
	return this->year;
}

int Date::getMonth() const
{
	return this->month;
}

int Date::getWeekday() const
{
	// For now, all months start on the same weekday (Monday).
	return this->day % Date::DAYS_PER_WEEK;
}

int Date::getDay() const
{
	return this->day;
}

std::string Date::getOrdinalDay() const
{
	// The current day is zero-based, so add one to get the "actual" day.
	const int displayedDay = this->day + 1;
	const int ordinalDay = displayedDay % 10;

	auto dayString = std::to_string(displayedDay);
	if (ordinalDay == 1)
	{
		dayString += "st";
	}
	else if (ordinalDay == 2)
	{
		dayString += "nd";
	}
	else if (ordinalDay == 3)
	{
		dayString += "rd";
	}
	else
	{
		dayString += "th";
	}

	return dayString;
}

int Date::getSeason() const
{
	return ((this->month + 10) % Date::MONTHS_PER_YEAR) / 3;
}

void Date::incrementYear()
{
	this->year++;
}

void Date::incrementMonth()
{
	this->month++;

	if (this->month == Date::MONTHS_PER_YEAR)
	{
		this->incrementYear();
		this->month = 0;
	}
}

void Date::incrementDay()
{
	this->day++;

	if (this->day == Date::DAYS_PER_MONTH)
	{
		this->incrementMonth();
		this->day = 0;
	}
}
