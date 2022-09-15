using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi
{
    class Customer
    {
        // Enums
        public enum Roles
        {
            RoleAdministrator = 1, RoleDriver = 2, RoleUser =3
        }

        public enum Columns 
        {
            ID = 0, UCN = 1, NAME = 2, ORDERS_MADE = 3, ROLE_ID = 4, USERNAME = 5, PASSWORD = 6
        }

        // Полета в таблицата CUSTOMERS
        public Int32 nId;
        public string strUcn;
        public string strName;
        public Int32 nOrdersMade;
        public Int32 nRoleId;
        public string strUsername;
        public byte[] byPassword;

        public bool b_Last_Operation_Status = true;

        public Customer()
        {
            this.nId = 0;
            this.strUcn = "";
            this.strName = "";
            this.nOrdersMade = 0;
            this.nRoleId = 0;
            this.strUsername = "";
        }

        public Customer(SqlDataReader oSqlDataReader)
        {
            this.b_Last_Operation_Status = Read_One_Customer(oSqlDataReader);
        }

        public string GetRoleText()
        {
            string strRole = "";
            switch (this.nRoleId)
            {
                case (int)Roles.RoleAdministrator:
                    strRole = "Administrator";
                    break;
                case (int)Roles.RoleDriver:
                    strRole = "Driver";
                    break;
                case (int)Roles.RoleUser:
                    strRole = "User";
                    break;
                default:
                    strRole = "Unknown";
                    break;
            }
            return strRole;
        }


        public bool Read_One_Customer(SqlDataReader oSqlDataReader)
        {
            if (!oSqlDataReader.Read())
                return false;

            this.nId = (Int32)(oSqlDataReader.GetValue((int)Columns.ID));
            this.strUcn = oSqlDataReader.GetValue((int)Columns.UCN).ToString();
            this.strName = oSqlDataReader.GetValue((int)Columns.NAME).ToString();
            this.nOrdersMade = (Int32)(oSqlDataReader.GetValue((int)Columns.ORDERS_MADE));
            this.nRoleId = (Int32)(oSqlDataReader.GetValue((int)Columns.ROLE_ID));
            this.strUsername = oSqlDataReader.GetValue((int)Columns.USERNAME).ToString();
            this.byPassword = (byte[])(oSqlDataReader.GetValue((int)Columns.PASSWORD));

            return true;
        }

        public override string ToString()
        {
            string strResult = "";
            strResult += this.nId + "; " + this.strUcn + "; " + this.strName + "; " +
                this.nOrdersMade + "; " + this.nRoleId + "; " + this.strUsername + "; " + this.byPassword + ";\n";
            return strResult;
        }
    }
}
