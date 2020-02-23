/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */
#include "../includes/scheduler.h"

bool Scheduler::isEmpty() {
	return ready_q->empty();
}
void Scheduler::add(PCB p) {
	ready_q->push(p);
}
PCB Scheduler::getNext() {
	PCB rt;
	rt = ready_q->front();
	if (!ready_q->empty()) {
		ready_q->pop();
	}
	return rt;
}
bool Scheduler::time_to_switch_processes(int tik_count, PCB &p) {
	if (preemptive) {
		if ((p.required_cpu_time - p.remaining_cpu_time) % time_slice == 0) {
			return true;
		}
	}
	if (p.remaining_cpu_time <= 0) {
		return true;
	}
	return false;
}

