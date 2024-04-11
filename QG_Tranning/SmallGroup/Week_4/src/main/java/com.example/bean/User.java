package com.example.entity;

/**
 * @AUTHOR czj
 * package_name com.example.entity
 * @DATE 2024/4/8 14:52
 */

public class User {
    private int id;
    private String username;
    private String password;
    private String email;
    private int failedAttempts;

    // 构造函数、getter和setter方法

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public int getFailedAttempts() {
        return failedAttempts;
    }

    public void setFailedAttempts(int failedAttempts) {
        this.failedAttempts = failedAttempts;
    }
}
