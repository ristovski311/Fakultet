﻿namespace Functions
{
    public static class Extensions
    {
        public static string ShowCurrentTime(this DateTime dt)
        {
            return dt.ToString("dd.MM.yyyy. HH:mm:ss.");
        }
    }
}
