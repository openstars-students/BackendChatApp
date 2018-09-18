/* 
 * File:   Model.h
 * Author: trungthanh
 *
 * Created on February 01, 2018, 6:16 PM
 */

#ifndef _MODELDATA_H
#define _MODELDATA_H

#include <vector>
#include "messagestore_types.h"

namespace model {

    
    class ModelData {
    public:
        
        OpenStars::Platform::MessageStore::TMessageInfo data;
        
        ModelData(void) {            
        }

        void assignTo(OpenStars::Platform::MessageStore::TMessageInfo& value) const {
            value = data;
        }

        void assignFrom(const OpenStars::Platform::MessageStore::TMessageInfo& value) {
            this->data = value;
        }
        OpenStars::Platform::MessageStore::TErrorCode::type deleteLogicData(){
            OpenStars::Platform::MessageStore::TErrorCode error;
            this->data.status=0;
            //OpenStars::Platform::MessageStore::TErrorCode err;
            return error.EGood;
        }


    };

}

#endif 
