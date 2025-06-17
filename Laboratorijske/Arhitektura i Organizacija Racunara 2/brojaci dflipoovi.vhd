library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.numeric_std.all;

entity brojac is
generic(n : natural := 4);
port(
	smer : in std_logic;
    ce : in std_logic;
    rst : in std_logic;
    --din : in integer;
    clk : in std_logic;
    count : out std_logic_vector(n-1 downto 0)
);
end entity;

architecture br of brojac is

begin
	
    process(clk)
    variable internal : integer range 0 to (2**n-1);
    begin
    	
        if(clk'event and clk = '1') then
        	if(rst = '1') then
            	internal := '0';
            elsif(ce = '1') then
            	if(smer = '1') then
            		if(internal = 2**n-1) then
                		internal := 0;
                    else
                    	internal := internal +1;
                    end if;
                else
                	if(internal = 0) then
                		internal := 2**n-1;
                    else
                    	internal := internal - 1;
                    end if;--int0
           		end if;--smer
               else
               		internal := 0;
               end if; --ce
       	end if;
    
    count <= std_logic_vector(to_unsigned(internal,n));
    end process;
   
end architecture;


library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.numeric_std.all;

entity kolo is
generic(lol : natural := 9);
port
(
	klok : in std_logic;
    reset : in std_logic;
    cenable : in std_logic;
    smerbiraj : in std_logic;
    izlaz : out std_logic_vector(lol-1 downto 0)
);
end entity;

architecture kolovodja of kolo is
signal unutarnji : std_logic_vector(lol-1 downto 0);
begin
	instancabr : entity work.brojac(br)
    generic map(lol => n)
    port map(smerbiraj,cenable,reset, klok,unutarnji);
    
    spolja : for i in lol downto 0 loop generate
    begin
    
    	pitanje1 : if (i > n/2) generate
        	begin
            izlaz(i) <= unutarnji(i);
        
        else generate
        		signal d, q : std_logic;
               begin
               
               d <= unutarnji(i);
               q <= d when (clock'event and clock = '1') else q;
               izlaz(i) <= q;
                
        end generate pitanje1;
    	
    
	end generate spolja;


end architecture;