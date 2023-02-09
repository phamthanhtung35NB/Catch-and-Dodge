#include <iostream>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    CURLcode res;
  
    std::string data = "{\"name\":\"value\"}";
    std::string url = "https://your-firebase-project.firebaseio.com/data.json";
  
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        res = curl_easy_perform(curl);
  
        if (res != CURLE_OK) {
            std::cerr << "cURL failed: " << curl_easy_strerror(res) << std::endl;
        }
  
        curl_easy_cleanup(curl);
    }
  
    return 0;
}
