class Gfg {
public:
    map<string, string> hm;
    int gap;
    Gfg(int gap){
        this->gap = gap;
        hm.clear();
    }
    bool judgeOrNot(string &submissionId){
        string userName = "";
        string timeStamp = "";
        bool flag=false;
        for(int i=0;i<submissionId.length();i++){
            if(submissionId[i]=='@'){
                flag=true;continue;
            }
            if(flag) timeStamp+=submissionId[i];
            else userName+=submissionId[i];
        }
        if(hm.find(userName)==hm.end() ||
           check(hm[userName], timeStamp, gap)){
            hm[userName] = timeStamp;
            return true;
        }
        return false;
    }
    bool check(string lastSubmissionTime, string thisSubmissionTime, int gap){
        int lastSubmissionTimeInSeconds = convertToSeconds(lastSubmissionTime);
        int thisSubmissionTimeInSeconds = convertToSeconds(thisSubmissionTime);
        if(thisSubmissionTimeInSeconds < lastSubmissionTimeInSeconds)
            thisSubmissionTimeInSeconds += 86400;
        return thisSubmissionTimeInSeconds - lastSubmissionTimeInSeconds >= gap;
    }
    int convertToSeconds(string timeStamp){
        int hr = stoi(timeStamp.substr(0,2));
        int min = stoi(timeStamp.substr(3,2));
        int sec = stoi(timeStamp.substr(6,2));
        return hr * 3600 + min * 60 + sec;
    }
};