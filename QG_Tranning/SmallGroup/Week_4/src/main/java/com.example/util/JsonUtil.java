package com.example.util;

import com.google.gson.Gson;

/**
 * @AUTHOR czj
 * package_name com.example.util
 * @DATE 2024/4/9 15:24
 */



public class JsonUtil {

    private static final Gson gson = new Gson();

    public static String toJson(Object obj) {
        return gson.toJson(obj);
    }

    public static <T> T fromJson(String json, Class<T> classOfT) {
        return gson.fromJson(json, classOfT);
    }
}
