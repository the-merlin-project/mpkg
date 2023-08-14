#include <curl.h>
#include <stdio.h>

int fetch_url(char *url) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_CA_CACHE_TIMEOUT, 604800L);

    res = curl_easy_perform(curl);

    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed" ,
          curl_easy_strerror(res));
    
    curl_easy_cleanup(curl);

    curl_global_cleanup();

    return 0;
}



