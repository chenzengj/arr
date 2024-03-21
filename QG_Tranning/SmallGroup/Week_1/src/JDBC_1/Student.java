package JDBC_1;

import java.util.Date;

/**
 * @AUTHOR czj
 * package_name JDBC_1
 * @DATE 2024/3/20 19:51
 */


    public class Student {
        private int id;

        private String name;
        private int age;
        private Date born;

    public Student() {
    }

    public Student(int id, String name, int age, Date born) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.born = born;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setBorn(Date born) {
        this.born = born;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public Date getBorn() {
        return born;
    }

    @Override
        public String toString() {
            return "Student{" +
                    "id=" + id +
                    ", name='" + name+",age="+age+",birthday="+born+ '\''+
        '}';
        }
    }


