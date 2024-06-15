package database;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author alumne
 */

public class ManageDB {
     public static Connection open_connection() throws ClassNotFoundException{
        try{
            Class.forName("org.apache.derby.jdbc.ClientDriver");
            return DriverManager.getConnection("jdbc:derby://localhost:1527/pr2;user=pr2;password=pr2");
            
        } catch (SQLException e) {   
            System.err.println(e.getMessage());
        }
        return null;
    }
    
    public static void close_connection(Connection c){
        try {
            if (c != null) c.close();
            
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
    }    
}
