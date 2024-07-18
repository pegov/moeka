#include <stdio.h>

#include "cpr/cpr.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "api/api.h"

void test_moex() {
    cpr::Url url = {"https://iss.moex.com/iss/securities.json"};
    cpr::Response res = cpr::Get(url, cpr::Parameters{{"q", "Yandex"}});
    printf("status code = %lu\n", res.status_code);
    auto content_type = res.header["content-type"];
    printf("content type = %s\n", content_type.c_str());
    auto text = res.text;
    printf("text = %s\n", text.c_str());
}
