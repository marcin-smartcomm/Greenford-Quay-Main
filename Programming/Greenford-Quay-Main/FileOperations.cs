using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Greenford_Quay_Main
{
    public static class FileOperations
    {
        public static void saveRoomJson(string roomID, string fileName, string jsonData)
        {
            var serializerSettings = new JsonSerializerSettings();
            serializerSettings.NullValueHandling = NullValueHandling.Ignore;

            string absolutePath = @"../../user/RoomSettings/Room" + roomID + "/";
            try
            {
                File.Delete(absolutePath + fileName + ".json");
                File.WriteAllText(
                    absolutePath + fileName + ".json",
                    jsonData
                    );
            }
            catch (Exception ex)
            {
                ConsoleLogger.WriteLine("issue in fileManager.saveRoomData(): " + ex.ToString());
            }
        }

        public static string loadRoomJson(int roomID, string settingType)
        {
            try
            {
                string absolutePath = @"../../user/RoomSettings/Room" + roomID + "/";
                StreamReader sr = new StreamReader(absolutePath + settingType + ".json");

                string json = sr.ReadToEnd();
                sr.Close();

                return json;
            }
            catch (Exception ex)
            {
                ConsoleLogger.WriteLine("issue in fileManager.loadRoomJson\n" + ex.ToString());
                return "";
            }
        }
        public static void saveCoreJson(string fileName, string jsonData)
        {
            var serializerSettings = new JsonSerializerSettings();
            serializerSettings.NullValueHandling = NullValueHandling.Ignore;

            string absolutePath = @"../../user/";
            try
            {
                File.Delete(absolutePath + fileName + ".json");
                File.WriteAllText(
                    absolutePath + fileName + ".json",
                    jsonData
                    );
            }
            catch (Exception ex)
            {
                ConsoleLogger.WriteLine("issue in fileManager.saveRoomData(): " + ex.ToString());
            }
        }

        public static string loadCoreInfo(string jsonFileName)
        {
            try
            {
                string absolutePath = @"../../user/";
                StreamReader sr = new StreamReader(absolutePath + $"{jsonFileName}.json");

                string json = sr.ReadToEnd();
                sr.Close();

                return json;
            }
            catch (Exception ex)
            {
                ConsoleLogger.WriteLine("issue in fileManager.loadMicrosoftInfo()\n" + ex.ToString());
                return null;
            }
        }

        public static List<string> GetRoomDirectories()
        {
            try
            {
                List<string> roomDirectories = Directory.GetDirectories(@"..\..\user\RoomSettings").ToList();
                return roomDirectories;
            }
            catch (Exception ex) { ConsoleLogger.WriteLine(ex.Message); return null; }
        }
    }
}
