package com.example.util;

import java.util.Arrays;
import java.util.List;

/**
 * @AUTHOR czj
 * package_name com.example.util
 * @DATE 2024/4/8 20:03
 */

public class StringUtil {

    private static final List<String> SENSITIVE_WORDS = Arrays.asList("原神", "傻逼", "牛魔");

    public static boolean containsSensitiveWords(String str) {
        for (String word : SENSITIVE_WORDS) {
            if (str.contains(word)) {
                return true;
            }
        }
        return false;
    }
}