/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/dispatcher.h"
PCB Dispatcher::get_from_CPU(){
	if(is_valid_job_on_cpu){
		return cpu->get_process_off_core();


	}else{

		PCB tmp;
		return tmp;
	}
}
void Dispatcher::put_on_CPU(PCB &process){
	cpu->put_process_on_core(process);
}
bool Dispatcher::isValidJobOnCPU(){
	PCB tmp = cpu->get_COPY_of_Current_Process();
	if(tmp.isEmpty()){
		is_valid_job_on_cpu = false;
		return false;
	}
	is_valid_job_on_cpu = true;
	return true;
}
