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
	ready_q->pop();
	return ready_q->front();
}
bool Scheduler::time_to_switch_processes(int tik_count, PCB &p) {
	if (p.remaining_cpu_time == 0) {
		return true;
	}
	if (preemptive) {
		if (tik_count >= time_slice) {
			return true;
		}
	}

	return false;

}

