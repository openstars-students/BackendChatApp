/* 
 * File:   Model.h
 * Author: trungthanh
 *
 * Created on February 01, 2018, 6:16 PM
 */

#ifndef _MODELDATA_H
#define _MODELDATA_H

#include <vector>
#include "conversationstore_types.h"

namespace model {

    
    class ModelData {
    public:
        
        OpenStars::Platform::ConversationStore::TConversationInfo data;
        
        ModelData(void) {            
        }

        void assignTo(OpenStars::Platform::ConversationStore::TConversationInfo& value) const {
            value = data;
        }

        void assignFrom(const OpenStars::Platform::ConversationStore::TConversationInfo& value) {
            this->data = value;
        }


    };

}

#endif 
