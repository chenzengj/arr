package CRUD_1;

import JDBC_1.Student;
import java.util.Date;
//import java.sql.Date;
import java.util.Scanner;

/**
 * @AUTHOR czj
 * package_name CRUD_1
 * @DATE 2024/3/20 11:11
 */
public class CRUDUtilsTest {
    public static void main(String[] args) throws Exception {
        CRUDUtilsTest crudUtilsTest = new CRUDUtilsTest();
        crudUtilsTest.findByID();
       // crudUtilsTest.insert();
        //crudUtilsTest.update();
        crudUtilsTest.delete();
    }
    public void findByID()  {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入查询的id：");
        int id=scanner.nextInt();
        Student stu=CRUDUtils.findById(id);
        System.out.println(stu);

    }
    /*
  	新增学生信息
*/

    public void insert() throws Exception {
        Date date=new Date();
        Student stu = new Student(4,"mary",27,date);
        int result = CRUDUtils.insert(stu);
        if(result != 0) {
            System.out.println("新增成功");
        }else {
            System.out.println("新增失败");
        }
    }
    /*
        修改学生信息
    */
    public void update() throws Exception {
        Student stu = CRUDUtils.findById(5);
        stu.setName("jerry");

        int result = CRUDUtils.update(stu);
        if(result != 0) {
            System.out.println("修改成功");
        }else {
            System.out.println("修改失败");
        }
    }
    /*
    删除学生信息
*/
    public void delete() {
        int result = CRUDUtils.delete(5);

        if(result != 0) {
            System.out.println("删除成功");
        }else {
            System.out.println("删除失败");
        }
    }


}
