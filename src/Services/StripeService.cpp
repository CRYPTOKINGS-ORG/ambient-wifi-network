#include "StripeService.h"
#include <curl/curl.h>

std::string StripeService::createCheckout() {
    CURL* curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, "https://api.stripe.com/v1/checkout/sessions");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);

    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Authorization: Bearer sk_test_replace_me");

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_perform(curl);

    return "ok";
}
