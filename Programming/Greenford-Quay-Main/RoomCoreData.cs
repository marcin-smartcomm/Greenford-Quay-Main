using System.Collections.Generic;

namespace Greenford_Quay_Main
{
    public class RoomMenuItem
    {
        public string menuItemName { get; set; }
        public string menuItemPageAssigned { get; set; }
        public string volControlType { get; set; }
        public bool tvRequired { get; set; }
        public int tvHDMIRequired { get; set; }
    }

    public class RoomCoreData
    {
        public int roomID { get; set; }
        public int floor { get; set; }
        public string roomName { get; set; }
        public int leftNeighbour { get; set; }
        public int rightNeighbour { get; set; }
        public List<RoomMenuItem> menuItems { get; set; }
        public bool tpLocked { get; set; }
        public string sourceSelected { get; set; }
        public int volLevel { get; set; }
        public bool volMute { get; set; }
        public bool tvCardRequired { get; set; }
        public uint skyIRPort { get; set; }
    }

    public class TPLockedReport
    {
        public int roomID { get; set; }
        public bool tpLocked { get; set; }
    }
}
