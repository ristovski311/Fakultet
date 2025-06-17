-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity brojac is
generic(n: natural := 4);
port
(
	clock : in bit;
	smer : in bit;
    reset : in bit;
    count: out std_logic_vector(n downto 0)
); end entity;

architecture brojac_arch of brojac is
begin

	broji : process(clock)
    	variable cnt_int : integer range 0 to (2**n - 1);
    begin
    	
        if(clock'event and clock = '1') then
    
    		if(reset = '1') then
            	cnt_int := 0;
            elsif(smer = '1') then
            	cnt_int := cnt_int + 1;
            else
            	cnt_int := cnt_int - 1;
                
            end if;
    	end if;
    	count <= std_logic_vector(to_unsigned(cnt_int, n));
    end process;
    

end architecture;




---



-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;


entity testbench is
generic(m : natural := 5);
end entity;

architecture tb of testbench is

signal clk_tb, smer_tb, reset_tb : bit;
signal count_tb : std_logic_vector(m downto 0);

begin

	dut: entity work.brojac(brojac_arch)
    generic map(n => m)
    port map(clk_tb, smer_tb, reset_tb, count_tb);

	stimulus: process is
    begin
    
    	smer_tb <= '1';
        reset_tb <= '1';
    	clk_tb <= '1';
        clk_tb <= '0';
        wait for 10ps;
        reset_tb <= '0';
    	clk_tb <= '1';
        clk_tb <= '0';
        wait for 10ps;
        clk_tb <= '1';
        clk_tb <= '0';
        wait for 10ps;
        clk_tb <= '1';
        clk_tb <= '0';
        wait for 10ps;
        
        
    
    end process;


end architecture;