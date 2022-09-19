using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BetterCallTaxi.Models
{
    class Role
    {
        // Enums
        public enum Columns
        {
            ID = 0, ROLE = 1
        }

        public bool b_Last_Operation_Status = true;

        // Полета от таблиата ROLES
        public Int32 nId { get; set; }
        public string strRole { get; set; }

        public Role()
        {
            this.nId = 0;
            this.strRole = "";
        }

        public Role(int nId, string strRole)
        {
            this.nId = nId;
            this.strRole = strRole;
        }

        public Role(SqlDataReader oSqlDataReader)
        {
            this.b_Last_Operation_Status = Read_One_Role(oSqlDataReader);
        }

        private bool Read_One_Role(SqlDataReader oSqlDataReader)
        {
            if (!oSqlDataReader.Read())
                return false;

            this.nId = (Int32)(oSqlDataReader.GetValue((int)Columns.ID));
            this.strRole = (string)(oSqlDataReader.GetValue((int)Columns.ROLE));

            return true;
        }
    }

    class RolesReader
    {
        public List<Role> oRoles;

        public RolesReader()
        { this.oRoles = new List<Role>(); }

        public bool Read_Many_Roles(SqlDataReader oSqlDataReader)
        {
            this.oRoles = new List<Role>();
            while (oSqlDataReader.Read())
            {
                Role recRole = new Role((int)(oSqlDataReader.GetValue((int)Role.Columns.ID))
                                        , oSqlDataReader.GetValue((int)Role.Columns.ROLE).ToString());
                this.oRoles.Add(recRole);
            }

            return true;
        }
    }

}
