using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi
{
    class DatabaseManager
    {
        private SqlConnection oSqlConnection;

        public DatabaseManager()
        {
            this.oSqlConnection = new SqlConnection();
            this.oSqlConnection.ConnectionString = GlobalConstants.CONNECTION_STRING;
            this.oSqlConnection.Open();
        }

        public SqlDataReader ExecuteQuery(string strQuery)
        {
            SqlCommand oSqlCommand = new SqlCommand(strQuery, this.oSqlConnection);
            oSqlCommand.CommandType = CommandType.Text;
            SqlDataReader oSqlDataReader = oSqlCommand.ExecuteReader();

            return oSqlDataReader;
        }

        public bool LoginAuthentication(string strUsername, string strPassword)
        {
            // Подготовка на процедурата
            SqlCommand oSqlCommand = new SqlCommand(GlobalConstants.LOGIN_AUTHENTICATION, this.oSqlConnection);

            // Потребителско име
            SqlParameter oSqlParameterUsername = new SqlParameter("@USERNAME", SqlDbType.VarChar);
            oSqlParameterUsername.Value = strUsername;
            oSqlCommand.Parameters.Add(oSqlParameterUsername);

            // Парола
            SqlParameter oSqlParameterPassword = new SqlParameter("@PASSWORD", SqlDbType.VarChar);
            oSqlParameterPassword.Value = strPassword;
            oSqlCommand.Parameters.Add(oSqlParameterPassword);

            // Резултат от процедурата - дали е валидна двойката име и парола
            SqlParameter oSqlParameterResult = new SqlParameter("@RESULT", SqlDbType.Int);
            oSqlParameterResult.Direction = ParameterDirection.Output;
            oSqlCommand.Parameters.Add(oSqlParameterResult);

            // Ще изпълняваме процедура, а не просто query
            oSqlCommand.CommandType = CommandType.StoredProcedure;

            // Изпълняваме процедурата
            Int32 nResult = Convert.ToInt32(oSqlCommand.ExecuteScalar());
            
            if (nResult != 1)
                return false;

            return true;
        }

        public bool Check_Username_Availability(string strUsername)
        {
            // Подготовка на процедурата
            SqlCommand oSqlCommand = new SqlCommand(GlobalConstants.CHECK_USERNAME_AVAILABILITY, this.oSqlConnection);

            // Потребителско име
            SqlParameter oSqlParameterUsername = new SqlParameter("@USERNAME", SqlDbType.VarChar);
            oSqlParameterUsername.Value = strUsername;
            oSqlCommand.Parameters.Add(oSqlParameterUsername);

            // Резултат от процедурата - дали е свободно името
            SqlParameter oSqlParameterResult = new SqlParameter("@RESULT", SqlDbType.Int);
            oSqlParameterResult.Direction = ParameterDirection.Output;
            oSqlCommand.Parameters.Add(oSqlParameterResult);

            // Ще изпълняваме процедура, а не просто query
            oSqlCommand.CommandType = CommandType.StoredProcedure;

            // Изпълняваме процедурата
            Int32 nResult = Convert.ToInt32(oSqlCommand.ExecuteScalar());

            if (nResult != 1)
                return false;

            return true;
        }

    }
}
