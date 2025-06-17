--counter



library IEEE;
use IEEE.std_logic_1164.all;

entity bcd_1c_counter is
port
(
	clock, reset : in bit;
    count : out std_logic_vector(3 downto 0)
);
end entity;

architecture bcd_1c_cnt_arch of bcd_1c_counter is
begin
	process(reset, clock) is
    	variable count_int : std_logic_vector(3 downto 0);
		variable svaka_druga : bit;
    begin
    	if(reset = '1') then
        	count_int := "0000";
            svaka_druga := '0';
        elsif(clock'event and clock = '1') then
            svaka_druga := not svaka_druga;
            if(svaka_druga = '1') then    
                    case (count_int) is
                    when "0000" => count_int := "0001";
                    when "0001" => count_int := "0010";
                    when "0010" => count_int := "0011";
                    when "0011" => count_int := "0100";
                    when "0100" => count_int := "0101";
                    when "0101" => count_int := "0110";
                    when "0110" => count_int := "0111";
                    when "0111" => count_int := "1000";
                    when "1000" => count_int := "1001";
                    when others => count_int := "0000";
        			end case;
            end if;
        end if;
        count <= count_int;
    end process;
end architecture;



---16


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity counter is
port
(
	clock, reset : in bit;
    count : out integer
);
end entity;

architecture counter_arch of counter is
begin
	process is
    	variable count_int : integer := 0;
    begin
    	count <= count_int;
    	spo: loop
        	unu: loop
            	wait until reset = '1' or clock = '1';
                exit when reset = '1';
                if(count_int = 15) then
                	count_int := 0;
                else
                	count_int := count_int + 1;
                end if;
                count <= count_int;
            end loop unu;
            count_int := 0;
            count <= count_int;
            wait until reset = '0';
        end loop spo;
    end process;
end architecture;


--reg

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity reg is
generic(n : integer := 8);
port
(
	wr, clock : in std_logic;
    din : in std_logic_vector(n-1 downto 0);
    dout : out std_logic
);
end entity;

architecture reg_arch of reg is
begin
	process is
    variable data : std_logic_vector(n-1 downto 0);
    begin
    	wait until wr = '1';
        data := din;
        for i in n-1 downto 0 loop
        	wait until clock'event and clock = '1';
        	dout <= data(i);
        end loop;
        wait until clock'event and clock = '1';
        dout <= 'Z';
    end process;
end architecture;


-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity testbench is
generic(wit : integer := 4);
end entity;

architecture tb of testbench is
signal wr_tb, dout_tb : std_logic;
signal clock_tb : std_logic := '0';
signal din_tb : std_logic_vector(wit-1 downto 0);
begin
	dut1: entity work.reg(reg_arch)
    generic map(n => wit)
    port map(wr_tb, clock_tb, din_tb, dout_tb);
    
    clock_tb <= not clock_tb after 1ns;
    
    stimulus: process is
    begin
    	
        din_tb <= "1011";
        wr_tb <= '0';
        wait for 2ns;
        wr_tb <= '1';
        wait for 1ns;
        wr_tb <= '0';
        wait for 1ns;
        wr_tb <= '1';
        wait for 1ns;
        din_tb <= "0110";
        wait for 1ns;
        
        
        
    end process;
end architecture;


------NE RADI PROPALI POKUSAJ


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity cnt is
port
(
	clock, reset : in std_logic;
	counter : out std_logic_vector(7 downto 0)
);
end entity;

architecture arch_cntr of cnt is
begin
	process(clock,reset) is
    	variable c1, c2 : std_logic_vector(3 downto 0);
    begin
    	if(reset = '1') then
        	c1 := "0000";
            c2 := "0000";
        elsif(clock'event and clock = '1') then
        	case(c1) is
            when "0000" => if(c1 = "1000") then c1 := "0001"; end if;
            when "0001" => if(c1 = "1001") then c1 := "0010"; end if;
            when "0010" => if(c1 = "1001") then c1 := "0011"; end if;
            when "0011" => if(c1 = "1001") then c1 := "0100"; end if;
            when "0100" => if(c1 = "1001") then c1 := "0101"; end if;
            when "0101" => if(c1 = "1001") then c1 := "0110"; end if;
            when "0110" => if(c1 = "1001") then c1 := "0111"; end if;
            when "0111" => if(c1 = "1001") then c1 := "1000"; end if;
            when "1000" => if(c1 = "1001") then c1 := "1001"; end if;
            when others => if(c1 = "1001") then c1 := "0000"; end if;
            end case;
        
        	case(c2) is
            when "0000" => c2 := "0001";
            when "0001" => c2 := "0010";
            when "0010" => c2 := "0011";
            when "0011" => c2 := "0100";
            when "0100" => c2 := "0101";
            when "0101" => c2 := "0110";
            when "0110" => c2 := "0111";
            when "0111" => c2 := "1000";
            when "1000" => c2 := "1001";
            when others => c2 := "0000";
            end case;
        end if;
        counter <= c1&c2;
    end process;
end architecture;

---- NE RADI ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^666




IPAK RADI ALI RADI OVO:

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity cnt is
port
(
	clock, reset : in std_logic;
	counter : out std_logic_vector(7 downto 0)
);
end entity;

architecture arch_cntr of cnt is
begin
	process(clock,reset) is
    	variable c1, c2 : std_logic_vector(3 downto 0);
    begin
    	if(reset = '1') then
        	c1 := "0000";
            c2 := "0000";
        elsif(clock'event and clock = '1') then
        
        
        	case(c2) is
            when "0000" => c2 := "0001";
            when "0001" => c2 := "0010";
            when "0010" => c2 := "0011";
            when "0011" => c2 := "0100";
            when "0100" => c2 := "0101";
            when "0101" => c2 := "0110";
            when "0110" => c2 := "0111";
            when "0111" => c2 := "1000";
            when "1000" => c2 := "1001";
            when others => c2 := "0000";
            end case;
            
            case(c1) is
            when "0000" => if(c2 = "1001") then c1 := "0001"; end if;
            when "0001" => if(c2 = "1001") then c1 := "0010"; end if;
            when "0010" => if(c2 = "1001") then c1 := "0011"; end if;
            when "0011" => if(c2 = "1001") then c1 := "0100"; end if;
            when "0100" => if(c2 = "1001") then c1 := "0101"; end if;
            when "0101" => if(c2 = "1001") then c1 := "0110"; end if;
            when "0110" => if(c2 = "1001") then c1 := "0111"; end if;
            when "0111" => if(c2 = "1001") then c1 := "1000"; end if;
            when "1000" => if(c2 = "1001") then c1 := "1001"; end if;
            when others => if(c2 = "1001") then c1 := "0000"; end if;
            end case;
        end if;
        counter <= std_logic_vector'(c1,c2);
    end process;
end architecture;


-------3cifreni preko procesa i konkatenacije i kastovanjaa WAIIIIt


-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity counter is
port
(
	clock : in bit;
    wr, ce : in bit;
    din : in integer;
    count : out std_logic_vector(11 downto 0)
);
end entity;

architecture arch of counter is
begin

	process is
        variable count_int : integer := 115;
    begin
    	count <= std_logic_vector(to_unsigned((count_int / 100),4)) & std_logic_vector(to_unsigned(((count_int / 10) mod 10),4))
             & std_logic_vector(to_unsigned((count_int mod 10),4));
        loop
        	wait until clock'event and clock = '1' and wr = '0' and ce = '1';
            exit when count_int = 0;
            count_int := count_int - 1;
            count <= std_logic_vector(to_unsigned((count_int / 100),4)) & std_logic_vector(to_unsigned(((count_int / 10) mod 10),4))
             & std_logic_vector(to_unsigned((count_int mod 10),4));
        end loop;
        wait until wr = '1' and ce = '0' and clock'event and clock = '1';
        count_int := din;
        
    end process;

end architecture;









--------------------3cifr sa sensitivity radi


-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity counter is
port
(
	clock : in bit;
    wr, ce : in bit;
    din : in integer;
    count : out std_logic_vector(11 downto 0)
);
end entity;

architecture arch of counter is
begin

	process(clock, wr, ce) is
        variable count_int : integer := 115;
    begin
    	count <= std_logic_vector(to_unsigned((count_int / 100),4)) & 					std_logic_vector(to_unsigned(((count_int / 10) mod 10),4)) & std_logic_vector(to_unsigned((count_int mod 10),4));
        if(wr = '0' and ce = '1') then
        	if(clock'event and clock = '1') then
            	if(count_int = 0) then
                	count_int := din;
            	else
            		count_int := count_int - 1;
            		count <= std_logic_vector(to_unsigned((count_int / 100),4)) & std_logic_vector(to_unsigned(((count_int / 10) mod 10),4)) & std_logic_vector(to_unsigned((count_int mod 10),4));
				end if;
            end if;
        elsif(wr = '1' and ce = '0') then
        	count_int := din;
        else
        	count <= (others => 'Z');
        end if;
    end process;
end architecture;


-------n generic osnova

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;


entity counter_int is
generic
(
	n : natural := 8
);
port
(
	clock : in bit;
   	wr : in bit;
    ce : in bit;
    din : in natural;
    count : out natural
);
end entity;

architecture cntr_arch of counter_int is
begin

	process(clock,wr,ce,din) is
    	variable count_int : natural := n-1 ;
	begin
    	 count <= count_int;
        if(clock'event and clock = '1') then
        	
            if(wr = '1') then
            	count_int := (din mod n);
            elsif(ce = '1') then
            	if(count_int = 0) then
                	count_int := n-1;
                else
            		count_int := (count_int - 1) mod n;
                end if;
            end if;
            count <= count_int;
        end if;
        
    end process;
end architecture;






--tb




-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity testbench is
generic(osnova : natural := 7);
end entity;

architecture comp_tb of testbench is
signal wr_tb, ce_tb : bit;
signal clock_tb : bit := '0';
signal din_tb : natural;
signal count_tb : natural;
begin
DUT : entity work.counter_int(cntr_arch)
generic map( n => osnova)
port map(clock_tb, wr_tb, ce_tb, din_tb, count_tb);

clock_tb <= not clock_tb after 50ps;

stimulus : process is
begin
	
    wr_tb <= '0';
    ce_tb <= '1';
    din_tb <= 342;
    wait for 1500ps;
    wr_tb <= '1';
    wait for 100ps;
    wr_tb <= '0';
    wait for 100ps;
    
end process;
end architecture;

    
