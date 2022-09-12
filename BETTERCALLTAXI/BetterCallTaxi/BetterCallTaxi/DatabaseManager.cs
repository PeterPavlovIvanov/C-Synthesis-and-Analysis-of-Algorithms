using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi
{
    class DatabaseManager
    {
        public const string CONNECTION_STRING = "Data Source=DESKTOP-PFQL6JD;Database=BetterCallTaxi;Integrated Security=True";
        private SqlConnection oSqlConnection;

        public DatabaseManager()
        {
            this.oSqlConnection = new SqlConnection();
            this.oSqlConnection.ConnectionString = CONNECTION_STRING;
            this.oSqlConnection.Open();
        }

        public SqlDataReader ExecuteQuery(string strQuery)
        {
            SqlCommand oSqlCommand = new SqlCommand(strQuery, this.oSqlConnection);
            oSqlCommand.CommandType = CommandType.Text;
            SqlDataReader oSqlDataReader = oSqlCommand.ExecuteReader();

            return oSqlDataReader;
        }

    }
}
