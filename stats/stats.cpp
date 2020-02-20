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

}
float Stats::get_av_response_time(){
	return av_response_time;
}
float Stats::get_av_turnaround_time(){
	return av_turnaround_time;
}
float Stats::get_av_wait_time(){
	return av_wait_time;
}
void Stats::calcStats(){

}
