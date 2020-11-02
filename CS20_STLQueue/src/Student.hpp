/*
 * Student.hpp
 *
 *  Created on: Oct 19, 2020
 *      Author: vessa
 */

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

class Student {
public:
	Student() {}
	virtual ~Student() {}

	float gpa;

	bool operator <(const Student& rValue) {
		if (this->gpa < rValue.gpa) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator >(const Student& rValue) {
		if (this->gpa > rValue.gpa) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator ==(const Student& rValue) {
		if (this->gpa == rValue.gpa) {
			return true;
		}
		else {
			return false;
		}
	}
};



#endif /* STUDENT_HPP_ */
