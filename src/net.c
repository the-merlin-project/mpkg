#include <curl.h>
#include <stdio.h>

int fetch_url(char *path) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL,

}
