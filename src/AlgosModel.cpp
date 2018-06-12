﻿#include "AlgosModel.h"

AlgosModel::AlgosModel() :__algoIdx__(0), __operaType__(ENCODE){}

// 读函数
QString AlgosModel::workspace(){
	return __algos__[__algoIdx__]->workspace();
}
QString AlgosModel::exe_path(){
	return __algos__[__algoIdx__]->exe_path(__operaType__);
}
const QStringList AlgosModel::algos_list(){
	QStringList algolist;
	for (int i = 0; i < __algos__.size(); i++){
		algolist.append(__algos__[i]->algo_name());
	}
	return algolist;
}
int AlgosModel::algo_idx(){
	return __algoIdx__;
}
OperaType AlgosModel::opera_type(){
	return __operaType__;
}
void AlgosModel::loadEnvAndArgs(QStringList &env, QStringList &args){
	__algos__[__algoIdx__]->loadEnvAndArgs(__operaType__, env, args);
}


// 写函数
void AlgosModel::add_algorithm(std::shared_ptr<IAlgorithm> algorithm){
	__algos__.append(algorithm);
}

void AlgosModel::algo_idx(int idx){
	__algoIdx__ = idx;
}

void AlgosModel::opera_type(OperaType type){
	__operaType__ = type;
}