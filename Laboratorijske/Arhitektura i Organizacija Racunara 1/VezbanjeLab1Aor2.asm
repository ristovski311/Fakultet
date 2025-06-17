-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;

entity dff_1 is
port(
	d : in bit;
    reset : in bit;
    clock : in bit;
    q : out bit
);
end entity dff_1;

architecture dff_async_conc of dff_1 is
begin
	q <= '0' when reset = '1' else d when clock'event and clock = '1';
end architecture;

architecture dff_sync_conc of dff_1 is
begin
	q <= '0' when reset = '1' and clock'event and clock = '1' else d when clock'event and clock = '1';
end architecture;

library IEEE;
use IEEE.std_logic_1164.all;

entity rsff_1 is
port(
	r : in bit;
    s : in bit;
    clock : in bit;
    q : out bit
);
end entity rsff_1;

architecture rsff_sync_conc of rsff_1 is
begin
	q <= '1' when s = '1' and clock'event and clock = '1' else 
    	'0' when r = '1' and clock'event and clock = '1';
end architecture;
	
architecture rsff_as_conc of rsff_1 is
begin
	q <= '0' when r = '1' else '1' when s = '1' and clock'event and clock = '1';
end architecture;

architecture rsff_as_proc of rsff_1 is
begin
	process(clock, r) is
    begin
    	if(r = '1') then
        	q <= '0';
        elsif(s = '1' and clock'event and clock = '1') then
         	q <= '1';
        end if;
    end process;
end architecture;
	
architecture rsff_sync_proc of rsff_1 is
begin
	process(clock) is
    begin
    	if(clock'event and clock = '1') then
        	if(r = '1') then
            	q <= '0';
            elsif(s = '1') then
            	q <= '1';
             end if;
         end if;
    end process;
end architecture;

library IEEE;
use IEEE.std_logic_1164.all;

entity jkff_1 is
port(
	j : in bit;
    k : in bit;
    reset : in bit;
    clock : in bit;
    q : out bit
);
end entity;

architecture jkff_as_conc of jkff_1 is
begin
	q <= '0' when reset = '1' else
    	not q when k = '1' and j = '1' and clock'event and clock = '1' else
        '0' when k = '1' and clock'event and clock = '1' else
        '1' when j = '1' and clock'event and clock = '1';
end architecture;

architecture jkff_sync_conc of jkff_1 is
begin
	q <= '0' when reset = '1' and clock'event and clock = '1' else
    	not q when k = '1' and j = '1' and clock'event and clock = '1' else
        '0' when k = '1' and clock'event and clock = '1' else
        '1' when j = '1' and clock'event and clock = '1';
end architecture;

architecture jkff_as_proc of jkff_1 is
begin
	process(clock, reset) is
    begin
    	if(reset = '1') then q <= '0';
        elsif(clock'event and clock = '1') then
        	if(j = '1' and k = '1') then q <= not q;
            elsif(j = '1') then q <= '1';
            elsif(k = '1') then q <= '0';
            else q <= q;
            end if;
        end if;
    end process;
end architecture;

architecture jkff_sync_proc of jkff_1 is
begin
	process(clock) is
    begin
    	if(clock = '1' and clock'event) then
        	if(reset = '1') then q<= '0';
            elsif(j = '1' and k = '1') then q <= not q;
            elsif(j = '1') then q <= '1';
            elsif(k = '1') then q <= '0';
            else q <= q;
            end if;
        end if;
    end process;
end architecture;


--arch

-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
end entity;

architecture testbench_ar of testbench is
signal clock_tb, reset_tb, d_tb, q_tb : bit;
begin
DUT : entity work.dff_1(dff_async_conc)
port map(d_tb, reset_tb, clock_tb, q_tb);
	stimulus : process is
    begin
    d_tb <= '1';
    reset_tb <= '1';
    wait for 1ns;
    clock_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
    clock_tb <= '0';
    wait for 1ns;
    reset_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
    d_tb <= '0';
    wait for 1ns;
    clock_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
end process;
end architecture;
    
    
    
    



-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;

entity dff1syncconc is
end entity;

architecture testbench_ar of dff1syncconc is
signal clock_tb, reset_tb, d_tb, q_tb : bit;
begin
DUT : entity work.dff_1(dff_sync_conc)
port map(d_tb, reset_tb, clock_tb, q_tb);
	stimulus : process is
    begin
    clock_tb <= '0';
    reset_tb <= '0';
    d_tb <= '1';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
    clock_tb <= '0';
    wait for 1ns;
    reset_tb <= '1';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
end process;
end architecture;




-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
end entity;

architecture testbench_ar of testbench is
signal clock_tb, r_tb, s_tb, q_tb : bit;
begin
DUT : entity work.rsff_1(rsff_as_conc)
port map(r_tb, s_tb, clock_tb, q_tb);
	stimulus : process is
    begin
    r_tb <= '1';
    s_tb <= '0';
    clock_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
    r_tb <= '0';
    s_tb <= '1';
    clock_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
    r_tb <= '0';
    s_tb <= '0';
    clock_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
    r_tb <= '1';
    s_tb <= '1';
    clock_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
end process;
end architecture;




-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
end entity;

architecture testbench_ar of testbench is
signal clock_tb, r_tb, s_tb, q_tb : bit;
begin
DUT : entity work.rsff_1(rsff_as_proc)
port map(r_tb, s_tb, clock_tb, q_tb);
	stimulus : process is
    begin
    r_tb <= '1';
    s_tb <= '0';
    clock_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
    r_tb <= '0';
    s_tb <= '1';
    clock_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
    r_tb <= '1';
    s_tb <= '0';
    clock_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    r_tb <= '0';
    s_tb <= '0';
    clock_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
    r_tb <= '1';
    s_tb <= '1';
    clock_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
end process;
end architecture;



-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;

entity testbench is
end entity;

architecture testbench_ar of testbench is
signal clock_tb, j_tb, k_tb, q_tb, reset_tb : bit;
begin
DUT : entity work.jkff_1(jkff_as_conc)
port map(j_tb, k_tb, reset_tb, clock_tb, q_tb);
	stimulus : process is
    begin
    clock_tb <= '0';
    j_tb <= '1';
    k_tb <= '0';
    reset_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
    clock_tb <='0';
    reset_tb <= '1';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
    reset_tb <= '0';
    k_tb <= '1';
    clock_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
    j_tb <= '0';
    clock_tb <= '0';
    wait for 1ns;
    clock_tb <= '1';
    wait for 1ns;
    
end process;
end architecture;


--mux

-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;

entity mux_2x1_slv_slv is
port(
	a, b : in std_logic_vector(7 downto 0);
    sel : in std_logic_vector(1 downto 0);
    f : out  std_logic_vector(7 downto 0)
);
end entity;

architecture mux_a_conc of mux_2x1_slv_slv is
begin
	with sel select
    f <= a when "01",
    	b when "10",
        (others => 'Z') when others;
end architecture;

architecture mux_a_proc of mux_2x1_slv_slv is
begin
	process(a,b,sel) is
    begin
    	if (sel = "01") then 
        	f <= a;
        elsif (sel = "10") then
         	f <= b;
        else
        	f <= (others => 'Z');
        end if;
    end process;
end architecture;

library IEEE;
use IEEE.std_logic_1164.all;

entity mux_2x1_slv_int is
port(
	a : in std_logic_vector(7 downto 0);
    b : in std_logic_vector(7 downto 0);
    sel : in integer;
    f : out std_logic_vector(7 downto 0)
);
end entity;

architecture mux_b_conc of mux_2x1_slv_int is
begin
	with sel select
    f <= a when 1,
    	b when 2,
        (others => 'Z') when others;
end architecture;

architecture mux_b_proc of mux_2x1_slv_int is
begin
	process(a,b,sel) is
    begin
    	if(sel = 1) then
        	f <= a;
        elsif(sel = 2) then
        	f <= b;
        else
        	f <= (others => 'Z');
        end if;
    end process;
end architecture;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity mux_4x1_sig_int is
port(
	a, b, c, d: in SIGNED (7 downto 0);
    sel : in std_logic_vector(1 downto 0);
    f : out signed(7 downto 0)
);
end entity;

architecture mux_c_conc of mux_4x1_sig_int is
begin
	with sel select
    f <= a when "00",
    	b when "01",
        c when "10",
        d when "11",
        (others => 'Z') when others;
end architecture;

architecture mux_c_proc of mux_4x1_sig_int is
begin
	process(a,b,c,d,sel) is
    begin
    	if(sel = "00") then f <= a;
   		elsif(sel = "01") then f <= b;
    	elsif(sel = "10") then f <= c;
    	elsif(sel = "11") then f <= d;
    	else f <= (others => 'Z');
    	end if;
    end process;
end architecture;

---comp

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;

entity comparator_max is
port(
	a,b,c,d : in signed(7 downto 0);
    f : out signed(7 downto 0)
);
end entity;

architecture comp_max_conc of comparator_max is
begin
	f <= a when a > b and a > c and a > d else
    	b when b > a and b > c and b > d else
        c when c > a and c > b and c > d else
        d when d >= a and d >= b and d >= c;
end architecture;

architecture comp_max_proc of comparator_max is
begin
	process(a,b,c,d) is
    begin
    	if(a > b and a > c and a > d) then f <= a;
        elsif(b > a and b > c and b > d) then f<= b;
        elsif(c > a and c > b and c > d) then f<= c;
        elsif(d >= a and d >= b and d >= c) then f<= d;
        end if;
    end process;
end architecture;