/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include "../includes/scheduler_SRTF.h"
#include <vector>
#include <algorithm>
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	preemptive = true;
	sort();
	return Scheduler::time_to_switch_processes(tick_count, p);
}

void Scheduler_SRTF::sort() {
	preemptive = true;
	std::vector<PCB> tmp;
	std::vector<PCB> tmp2;
	for (unsigned int i = 0; i < ready_q->size(); i++) {
		tmp.push_back(ready_q->front());
		ready_q->pop();
	}
	int size = tmp.size();
	int countArray[size];
	for (int i = 0; i < size; i++) {
		tmp2.push_back(tmp[i]);
		countArray[i] = 0;
	}
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (tmp[i].remaining_cpu_time > tmp[j].remaining_cpu_time) {
				countArray[i]++;
			} else {
				countArray[j]++;
			}
		}
		for (int i = 0; i < size; i++) {
			tmp2[countArray[i]] = tmp[i];
		}
		for(int i = 0;i < size;i++){
			ready_q->push(tmp2[i]);
		}
	}
}
void add(PCB p) {

}

