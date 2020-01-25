#pragma once
#define size_extend 10
#include<stdio.h>
template <typename T_Array>

class Array {
private:
	int times;
	int length;
	T_Array* values;

public:
	Array(){
		length = 0;
		times = 0;
		values = new T_Array[size_extend];
	}
	Array(int length) {
		this->length = length;
		times = length / size_extend + 1;
		values = new T_Array[times * size_extend];
	}
	Array(T_Array* a, int length) {
		this->length = length;
		times = length / size_extend + 1;
		values = new T_Array[times * size_extend];
		for (int i = 0; i < length; i++) {
			values[i] = a[i];
		}
	}

	int getLength() {
		return length;
	}

	void add_value(T_Array value) {
		length++;
		if (length >= (times * size_extend)) {
			times++;
			T_Array* temp = new T_Array[times * size_extend];
			for (int i = 0; i < length - 1; i++)
				temp[i] = values[i];
			values = new T_Array[times * size_extend];
			for (int i = 0; i < length - 1; i++)
				values[i] = temp[i];
		}
		values[length - 1] = value;
	}

	void delete_id(int id) {
		id = id - 1;
		T_Array* temp = new T_Array[times * size_extend];
		for (int i = 0; i < id; i++)
			temp[i] = values[i];
		int k = id;
		for (int i = id + 1; i < length; i++)
			temp[k++] = values[i];

		length--;
		if (length < ((times - 1) * size_extend)) {
			times--;
			values = new T_Array[times * size_extend];
		}
		for (int i = 0; i < length; i++)
			values[i] = temp[i];
	}

	void delete_value(T_Array value) {
		T_Array* temp = new T_Array[times * size_extend];
		int k = 0;
		for (int i = 0; i < length; i++) {
			if (values[i] != value)
				temp[k++] = values[i];
		}
		length = k;
		times = (length / size_extend) + 1;
		values = new T_Array[times * size_extend];
		for (int i = 0; i < length; i++)
			values[i] = temp[i];
	}

	void insert(int id, T_Array value) {
		id = id - 1;
		length++;
		if (length >= (times * size_extend)) {
			times++;
			T_Array* temp = new T_Array[times * size_extend];
			for (int i = 0; i < length - 1; i++)
				temp[i] = values[i];
			values = new T_Array[times * size_extend];
			for (int i = 0; i < length - 1; i++)
				values[i] = temp[i];
		}
		for (int i = length - 1; i > id; i--)
			values[i] = values[i - 1];
		values[id + 1] = value;
	}

	T_Array getId(int id) {
		return values[id - 1];
	}
};
