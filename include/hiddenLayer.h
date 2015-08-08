#ifndef __OUTPUT_LAYER_H__
#define __OUTPUT_LAYER_H__

#include "perceptronLayer.h"

class HiddenLayer : public PerceptronLayer {
	public:
		HiddenLayer(int neurons, int inputs, double b);
		virtual ~HiddenLayer();
		
};

#endif
