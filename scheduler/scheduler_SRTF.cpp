/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */
#include <vector>
#include "../includes/scheduler_SRTF.h"

bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	preemptive = true;
	sort();
	if (p.remaining_cpu_time <= 0) {
		return true;
	}
	if (!ready_q->empty()) {
		if (ready_q->front().remaining_cpu_time < p.remaining_cpu_time) {
			return true;
		}
	}
	return false;

}
/*
 * uses a temporary vector for bubble sort to sort ready_q
 */
void Scheduler_SRTF::sort() {
	preemptive = true;
	std::vector<PCB> tmp;
	std::vector<PCB> tmp2;
	int size = ready_q->size();
	for (int i = 0; i < size; i++) {
		tmp.push_back(ready_q->front());
		ready_q->pop();
	}
	int i, j;
	bool swapped;
	for (i = 0; i < size - 1; i++) {
		swapped = false;
		for (j = 0; j < size - i - 1; j++) {
			if (tmp[j].remaining_cpu_time > tmp[j + 1].remaining_cpu_time) {
				PCB tmp2 = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = tmp2;
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
	for (int i = 0; i < size; i++) {
		ready_q->push(tmp[i]);
	}
}

