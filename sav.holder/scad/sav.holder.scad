
drill = 3.5;
drillDistance = 4;
SAV_holes = 57;

length = 70;
width = 25;

wallWidth = 4.5;
clipL = 55.3;
clipW = 35;
clipH = 14;

supportL = 68;
supportW = wallWidth;
supportH = 14;

restL = 10;
restW = 1.5;
restH = supportH;


gripS = 3;

frameW = 6.3; // i3 frame width
M3NutD = 6.6;
M3NutH = 3;

module SAV_drills ( )
{
	cylinder ( r=drill/2, h=20, $fn=20 );
	translate ( [0,0,wallWidth-0.2])
		cylinder ( r=M3NutD/2, h=M3NutH, $fn=6 );

	translate ([SAV_holes, 0, 0])
	{
		cylinder ( r=drill/2, h=20, $fn=20 );
		translate ( [0,0,wallWidth-0.2])
			cylinder ( r=M3NutD/2, h=M3NutH, $fn=6 );
	}
}

module base (  )
{
	difference ()
	{
		union()
		{

			// Main clip structure
			difference ()
			{
				cube ([clipL+(2*wallWidth), clipW, clipH]);
				translate ([wallWidth, wallWidth, 0])
					cube ([clipL, clipW, clipH]); 
			}
		
			// base support and drills
			//translate ([-25,0,0])
			translate ([-19,0,0])
			{
				difference ()
				{
		
					union ()
					{
						cube ([supportL, supportW, supportH] );
						translate ([0, - restW, 0])
							cube ([restL, restW, restH]);
		
						translate ([supportL-restL, - restW, 0])
							cube ([restL, restW, restH]);
					}
				}
			}
		}
		translate ([-19+drillDistance+2, 2*wallWidth, clipH/2])
			rotate ([90, 0, 0])
			#SAV_drills();
	}
	
	// Grips
	translate ([wallWidth, clipW-wallWidth, 0])
		difference ()
		{
			rotate ([0,0,45])
				cube ([gripS,gripS,clipH]);
		}
	translate ([clipL + wallWidth, clipW-wallWidth, 0])
		rotate ([0,0,45])
			cube ([gripS,gripS,clipH]);

	// Reinforcement
	translate ([wallWidth, wallWidth, 0])
		difference ( )
		{
			cube ([clipH/2,clipH/2,clipH]);
			translate ([clipH/2,clipH/2,0])
				cylinder (r=clipH/2, h=clipH);
		}
	translate ([clipL-(clipH/2)+wallWidth, wallWidth, 0])
		difference ( )
		{
			cube ([clipH/2,clipH/2,clipH]);
			translate ([0,clipH/2,0])
				cylinder (r=clipH/2, h=clipH);
		}

	translate ([-(clipH/2), wallWidth, 0])
		difference ( )
		{
			cube ([clipH/2,clipH/2,clipH]);
			translate ([0,clipH/2,0])
				cylinder (r=clipH/2, h=clipH);
		}

	// support
	translate ([clipL/2, wallWidth, 0])
		cube ([8.5, clipW - wallWidth - frameW - (1.3*gripS), clipH]);
}

module frame ()
{
	translate ([wallWidth, clipW - frameW - 1.5*gripS, 0])
		cube([clipL, frameW, 60]);
}

base();
%frame ();


