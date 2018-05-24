﻿#pragma once
#pragma execution_character_set("utf-8")

#include "IPanelController.h"
#include "PanelStatusModel.h"
#include "IPanelView.h"

using namespace std;

void IPanelController::set_view(shared_ptr<IPanelView> view){
	__view__ = view;
	__view__->link_controller(*this);
	if (__status_model__.get()){
	
	}
}

void IPanelController::set_status_model(shared_ptr<PanelStatusModel> model){
	__status_model__ = model;
	if (__view__.get()){
		__status_model__->set_view(__view__);
	}
}