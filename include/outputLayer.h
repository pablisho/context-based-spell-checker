#ifndef __OUTPUT_LAYER_H__
#define __OUTPUT_LAYER_H__

#include "perceptronLayer.h"

class OutputLayer : public PerceptronLayer {
	public:
		OutputLayer(int neurons, int inputs, double b);
		virtual ~OutputLayer();
};

#endif
