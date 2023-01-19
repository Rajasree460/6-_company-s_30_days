class TransactionInformation {
    public:
    TransactionInformation() {
        
    }
    string name;
    int time;
    int amount;
    int transactionId; // this will be the index of original array at which the transaction occurs originally
    string city;
};

class Solution {
public:
    TransactionInformation* extractInformation(string transaction, int index) {
        TransactionInformation* transactionInfo = new TransactionInformation();
        
        // split string using comman and extract informatiom
        vector<string> res;
        string tmp;
        for(auto ch:transaction) {
            if(ch==',') {
                res.push_back(tmp);
                tmp.clear();
                continue;
            }
            tmp+=ch;
        }
        res.push_back(tmp);
        
        // populate transaction object
        transactionInfo->name = res[0];
        transactionInfo->time = stoi(res[1]);
        transactionInfo->amount = stoi(res[2]);
        transactionInfo->city = res[3];
        transactionInfo->transactionId = index;
        return transactionInfo;
    }

    
    vector<string> invalidTransactions(vector<string>& transactions) {
        
        int index = 0;
        
        // store the invalid trasaction IDs
        unordered_set<int> invalid_trasaction_ids;
        
        unordered_map<string,vector<TransactionInformation*>> store;
            
        for(auto transaction:transactions) {
            
            TransactionInformation* transactionInfo = extractInformation(transaction,index);
        
            // check if amount is greater than 1000
            if(transactionInfo->amount>1000) invalid_trasaction_ids.insert(transactionInfo->transactionId);
            
            // insert everything in a map
            store[transactionInfo->name].push_back(transactionInfo);            
            index++;
        }
        
        for(auto element:store) {
            
            vector<TransactionInformation*> tmp = element.second;
            
            // using a quadratic search find out invalid transactions
            for(int i=0;i<tmp.size();i++) {
                // time and city at which first trasaction occured
                int time1 = tmp[i]->time;
                string city1 = tmp[i]->city;
                
                for(int j=i+1;j<tmp.size();j++) {
                    // time and city at which second transaction occured
                    int time2 = tmp[j]->time;
                    string city2 = tmp[j]->city;
                    
                    //check if they occured within 60 minutes in different city
                    if(abs(time1-time2)<=60 && city1!=city2) {
                        invalid_trasaction_ids.insert(tmp[j]->transactionId);
                        invalid_trasaction_ids.insert(tmp[i]->transactionId);
                    }
                }
            }
        }
        
        // get invalid trasaction IDs and insert those to get final answer
        vector<string> invalid;
        for(int i=0;i<transactions.size();i++) {
            if(invalid_trasaction_ids.count(i)) {
                invalid.push_back(transactions[i]);
            }
        }
        return invalid;
    }
};
