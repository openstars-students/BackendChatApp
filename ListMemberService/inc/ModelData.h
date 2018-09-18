/* 
 * File:   Model.h
 * Author: trungthanh
 *
 * Created on February 01, 2018, 6:16 PM
 */

#ifndef _MODELDATA_H
#define _MODELDATA_H

#include <vector>
#include "listmemberservice_types.h"

namespace model {

    
    class ModelData {
    public:
        
        OpenStars::Platform::ListMemberService::TValue data;
        
        ModelData(void) {            
        }

        void assignTo(OpenStars::Platform::ListMemberService::TValue& value) const {
            value = data;
        }

        void assignFrom(const OpenStars::Platform::ListMemberService::TValue& value) {
            this->data = value;
        }


    };

}

#endif 
