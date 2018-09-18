/* 
 * File:   Model.h
 * Author: trungthanh
 *
 * Created on February 01, 2018, 6:16 PM
 */

#ifndef _MODELDATA_H
#define _MODELDATA_H

#include <vector>
#include "listmessageservice_types.h"

namespace model {

    
    class ModelData {
    public:
        
        OpenStars::Platform::ListMessageService::TValue data;
        
        ModelData(void) {            
        }

        void assignTo(OpenStars::Platform::ListMessageService::TValue& value) const {
            value = data;
        }

        void assignFrom(const OpenStars::Platform::ListMessageService::TValue& value) {
            this->data = value;
        }


    };

}

#endif 
