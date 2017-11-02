#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <string>
#include "svm.h"
#define Malloc(type,n) (type *)malloc((n)*sizeof(type))

class Classifier
{
private:
public:
	Classifier();
	~Classifier();

	//------------------------------------for training----------------------------------
	double crossvaldata[2];
	// for EPSILON-SVR {[i = 0] Cross Validation Mean squared error, [i = 1] Cross Validation Squared correlation coefficient}
	// for everything else {[1 = 0] Cross Validation Accuracy}
	struct svm_parameter param;		// set by parse_command_line
	struct svm_problem prob;		// set by read_problem
	struct svm_model *model;
	struct svm_node *x;
	struct svm_node *x_space;
	int cross_validation;
	int nr_fold;

	int doTraining();
	int read_problem(const char *filename);
	void set_param();
	void do_cross_validation();
	// -----------------------------------for prediction---------------------------------
	int max_nr_attr = 64;
	int predict_probability = 0;
	double *prob_estimates = NULL;
	double doPrediction(double * angles, int predict_P = 0);
	// -----------------------------------for both---------------------------------------
	char *line;
	int max_line_len;
	char input_file_name[1024] = "data_for_training";
	char model_file_name[1024] = "data_for_training.model";
	char* readline(FILE *input);
};

