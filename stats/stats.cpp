/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector):vec(&finished_vector){
	av_wait_time = 0;
	av_turnaround_time = 0;
	av_response_time = 0;
}

void Stats::showAllProcessInfo(){
	std::vector<PCB>::iterator tmp;
for(tmp = vec->begin();tmp != vec->end();tmp++){
	float t1 = tmp.base()->process_number;
	float t2 = tmp.base()->required_cpu_time;
	float t3 = tmp.base()->arrival_time;
	float t4 = tmp.base()->start_time;
	float t5 = tmp.base()->finish_time;
	std::cout<< "Process " << t1 << " Required CPU time:" << t2<<
			" arrived:" << t3 << " started:" << t4 <<
			" finished:" << t5<<std::endl;
}
}
float Stats::get_av_response_time(){
	std::vector<PCB>::iterator tmp;
	int counter = 0;
	float calc = 0;
	float total = 0;
	for(tmp = vec->begin();tmp != vec->end();tmp++){
		calc = tmp.base()->start_time - tmp.base()->arrival_time;
		total+=calc;
		counter++;
	}
	av_response_time = total/counter;
	return av_response_time;
}
float Stats::get_av_turnaround_time(){
	std::vector<PCB>::iterator tmp;
		int counter = 0;
		float calc = 0;
		float total = 0;
		for(tmp = vec->begin();tmp != vec->end();tmp++){
			calc = tmp.base()->finish_time - tmp.base()->arrival_time;
			total+=calc;
			counter++;
		}
		av_turnaround_time = total/counter;
	return av_turnaround_time;
}
float Stats::get_av_wait_time(){
	std::vector<PCB>::iterator tmp;
		int counter = 0;
		float calc = 0;
		float total = 0;
		for(tmp = vec->begin();tmp != vec->end();tmp++){
			calc = tmp.base()->finish_time - tmp.base()->arrival_time - tmp.base()->required_cpu_time;
			total+=calc;
			counter++;
		}
		av_wait_time = total/counter;
	return av_wait_time;
}
void Stats::calcStats(){

}
