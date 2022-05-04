{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 1,
			"revision" : 5,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 40.0, 82.0, 977.0, 610.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"assistshowspatchername" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-19",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1086.33349609375, 735.49993896484375, 150.0, 48.0 ],
					"text" : "When the incoming data goes above this number it sends a nag"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 758.052734375, 845.99993896484375, 150.0, 48.0 ],
					"text" : "When the incoming data goes above this number it sends a nag"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 497.552734375, 622.0, 150.0, 20.0 ],
					"text" : "Plant 1 data"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-7",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 758.052734375, 622.0, 150.0, 20.0 ],
					"text" : "Plant 2 data"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-25",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 649.052734375, 266.333343505859375, 58.0, 22.0 ],
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 1019.33331298828125, 595.18035888671875, 58.0, 22.0 ],
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1019.33331298828125, 651.18035888671875, 29.5, 22.0 ],
					"text" : "200"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 694.052734375, 710.0, 58.0, 22.0 ],
					"text" : "loadbang"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-1",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 694.052734375, 756.0, 29.5, 22.0 ],
					"text" : "200"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-2",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 977.33343505859375, 945.0, 29.5, 22.0 ],
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-110",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 650.052734375, 1039.486328125, 29.5, 22.0 ],
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"basictuning" : 440,
					"clipheight" : 91.0,
					"data" : 					{
						"clips" : [ 							{
								"absolutepath" : "rainstick.aif",
								"filename" : "rainstick.aif",
								"filekind" : "audiofile",
								"id" : "u734000397",
								"selection" : [ 0.0, 1.0 ],
								"loop" : 0,
								"content_state" : 								{

								}

							}
 ]
					}
,
					"followglobaltempo" : 0,
					"formantcorrection" : 0,
					"id" : "obj-103",
					"maxclass" : "playlist~",
					"mode" : "basic",
					"numinlets" : 1,
					"numoutlets" : 5,
					"originallength" : [ 0.0, "ticks" ],
					"originaltempo" : 120.0,
					"outlettype" : [ "signal", "signal", "signal", "", "dictionary" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 650.052734375, 1086.486328125, 150.0, 92.0 ],
					"pitchcorrection" : 0,
					"quality" : "basic",
					"timestretch" : [ 0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-75",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 977.33343505859375, 894.99993896484375, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-80",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "int" ],
					"patching_rect" : [ 1022.33343505859375, 786.99993896484375, 62.0, 22.0 ],
					"text" : "trigger b i"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-82",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 938.666748046875, 710.0, 52.0, 23.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-83",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1022.33343505859375, 747.49993896484375, 52.0, 23.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-84",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 977.33343505859375, 845.99993896484375, 130.0, 23.0 ],
					"text" : "if $i1 > $i2 then bang"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-88",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 977.33343505859375, 1134.8197021484375, 59.333335876464844, 59.333335876464844 ]
				}

			}
, 			{
				"box" : 				{
					"basictuning" : 440,
					"clipheight" : 20.0,
					"data" : 					{
						"clips" : [ 							{
								"absolutepath" : "senita-8ch.wav",
								"filename" : "senita-8ch.wav",
								"filekind" : "audiofile",
								"id" : "u269000384",
								"selection" : [ 0.0, 1.0 ],
								"loop" : 0,
								"content_state" : 								{

								}

							}
, 							{
								"absolutepath" : "/Users/adamalcock/iCloud Drive (Archive) - 1/Documents/Stuff/DeskTopCleanup/Vid2:3 Project/Samples/Processed/Reverse/198732__syntheon__spinning-bowl R.wav",
								"filename" : "198732__syntheon__spinning-bowl R.wav",
								"filekind" : "audiofile",
								"id" : "u469000643",
								"selection" : [ 0.145658263305322, 0.145658263305322 ],
								"loop" : 0,
								"content_state" : 								{
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"basictuning" : [ 440 ],
									"quality" : [ "basic" ],
									"pitchcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"speed" : [ 1.0 ]
								}

							}
, 							{
								"absolutepath" : "/Users/adamalcock/iCloud Drive (Archive) - 1/Documents/Stuff/DeskTopCleanup/HarryPotterSession Project/Samples/Imported/195568__jacobalcook__creature-roar-1.wav",
								"filename" : "195568__jacobalcook__creature-roar-1.wav",
								"filekind" : "audiofile",
								"id" : "u375000646",
								"selection" : [ 0.0, 1.0 ],
								"loop" : 0,
								"content_state" : 								{
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"basictuning" : [ 440 ],
									"quality" : [ "basic" ],
									"pitchcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"speed" : [ 1.0 ]
								}

							}
, 							{
								"absolutepath" : "/Users/adamalcock/iCloud Drive (Archive) - 1/Documents/Stuff/COLLEGE/FFT/188869__plingativator__jawharp-boing.wav",
								"filename" : "188869__plingativator__jawharp-boing.wav",
								"filekind" : "audiofile",
								"id" : "u720000649",
								"selection" : [ 0.0, 1.0 ],
								"loop" : 0,
								"content_state" : 								{
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"basictuning" : [ 440 ],
									"quality" : [ "basic" ],
									"pitchcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"speed" : [ 1.0 ]
								}

							}
, 							{
								"absolutepath" : "/Users/adamalcock/iCloud Drive (Archive) - 1/Documents/Stuff/DeskTopCleanup/Vid2:3 Project/Samples/Imported/176880__mickmon__inhale1.wav",
								"filename" : "176880__mickmon__inhale1.wav",
								"filekind" : "audiofile",
								"id" : "u822000652",
								"selection" : [ 0.0, 1.0 ],
								"loop" : 0,
								"content_state" : 								{
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"basictuning" : [ 440 ],
									"quality" : [ "basic" ],
									"pitchcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"speed" : [ 1.0 ]
								}

							}
, 							{
								"absolutepath" : "/Users/adamalcock/iCloud Drive (Archive) - 1/Documents/Stuff/DeskTopCleanup/Vid2:3 Project/Samples/Imported/149347__setuniman__prompt-q46k.wav",
								"filename" : "149347__setuniman__prompt-q46k.wav",
								"filekind" : "audiofile",
								"id" : "u753000655",
								"selection" : [ 0.0, 1.0 ],
								"loop" : 0,
								"content_state" : 								{
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"basictuning" : [ 440 ],
									"quality" : [ "basic" ],
									"pitchcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"speed" : [ 1.0 ]
								}

							}
, 							{
								"absolutepath" : "/Users/adamalcock/iCloud Drive (Archive) - 1/Documents/Stuff/COLLEGE/FFT/146264__setuniman__boing-0h-16mHlb.wav",
								"filename" : "146264__setuniman__boing-0h-16mHlb.wav",
								"filekind" : "audiofile",
								"id" : "u537000658",
								"selection" : [ 0.0, 1.0 ],
								"loop" : 0,
								"content_state" : 								{
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"basictuning" : [ 440 ],
									"quality" : [ "basic" ],
									"pitchcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"speed" : [ 1.0 ]
								}

							}
, 							{
								"absolutepath" : "/Volumes/SD/ElectroSamples/146264__setuniman__boing-0h-16m.wav",
								"filename" : "146264__setuniman__boing-0h-16m.wav",
								"filekind" : "audiofile",
								"id" : "u262000661",
								"selection" : [ 0.0, 1.0 ],
								"loop" : 0,
								"content_state" : 								{
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"basictuning" : [ 440 ],
									"quality" : [ "basic" ],
									"pitchcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"speed" : [ 1.0 ]
								}

							}
, 							{
								"absolutepath" : "/Users/adamalcock/iCloud Drive (Archive) - 1/Desktop/ElectroSamples/146264__setuniman__boing-0h-16m.wav",
								"filename" : "146264__setuniman__boing-0h-16m.wav",
								"filekind" : "audiofile",
								"id" : "u335000664",
								"selection" : [ 0.0, 1.0 ],
								"loop" : 0,
								"content_state" : 								{
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"basictuning" : [ 440 ],
									"quality" : [ "basic" ],
									"pitchcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"speed" : [ 1.0 ]
								}

							}
, 							{
								"absolutepath" : "/Users/adamalcock/iCloud Drive (Archive) - 1/Documents/Stuff/COLLEGE/FFT/146264__setuniman__boing-0h-16m.wav",
								"filename" : "146264__setuniman__boing-0h-16m.wav",
								"filekind" : "audiofile",
								"id" : "u240000667",
								"selection" : [ 0.0, 1.0 ],
								"loop" : 0,
								"content_state" : 								{
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"basictuning" : [ 440 ],
									"quality" : [ "basic" ],
									"pitchcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"speed" : [ 1.0 ]
								}

							}
, 							{
								"absolutepath" : "/Users/adamalcock/iCloud Drive (Archive) - 1/Documents/Stuff/COLLEGE/FFT/188869__plingativator__jawharp-boing.wav",
								"filename" : "188869__plingativator__jawharp-boing.wav",
								"filekind" : "audiofile",
								"id" : "u951000670",
								"selection" : [ 0.0, 1.0 ],
								"loop" : 0,
								"content_state" : 								{
									"originallengthms" : [ 0.0 ],
									"originaltempo" : [ 120.0 ],
									"basictuning" : [ 440 ],
									"quality" : [ "basic" ],
									"pitchcorrection" : [ 0 ],
									"formant" : [ 1.0 ],
									"followglobaltempo" : [ 0 ],
									"mode" : [ "basic" ],
									"timestretch" : [ 0 ],
									"slurtime" : [ 0.0 ],
									"formantcorrection" : [ 0 ],
									"pitchshift" : [ 1.0 ],
									"play" : [ 0 ],
									"originallength" : [ 0.0, "ticks" ],
									"speed" : [ 1.0 ]
								}

							}
 ]
					}
,
					"followglobaltempo" : 0,
					"formantcorrection" : 0,
					"id" : "obj-90",
					"maxclass" : "playlist~",
					"mode" : "basic",
					"numinlets" : 1,
					"numoutlets" : 5,
					"originallength" : [ 0.0, "ticks" ],
					"originaltempo" : 120.0,
					"outlettype" : [ "signal", "signal", "signal", "", "dictionary" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 977.33343505859375, 992.486331939697266, 285.333343505859375, 115.999992370605469 ],
					"pitchcorrection" : 0,
					"quality" : "basic",
					"timestretch" : [ 0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-70",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 777.38604736328125, 333.819580078125, 32.0, 22.0 ],
					"text" : "print"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-21",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 729.052734375, 660.819580078125, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-71",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 649.052734375, 660.819580078125, 50.0, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 12,
					"outlettype" : [ "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int", "int" ],
					"patching_rect" : [ 649.052734375, 570.819580078125, 167.0, 22.0 ],
					"text" : "unpack 0 0 0 0 0 0 0 0 0 0 0 0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-72",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 649.052734375, 539.48626708984375, 71.0, 22.0 ],
					"text" : "fromsymbol"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 649.052734375, 507.486236572265625, 40.0, 22.0 ],
					"text" : "itoa"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-73",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 649.052734375, 478.819580078125, 81.0, 22.0 ],
					"text" : "zl group 2000"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-12",
					"maxclass" : "newobj",
					"numinlets" : 3,
					"numoutlets" : 3,
					"outlettype" : [ "bang", "bang", "" ],
					"patching_rect" : [ 649.052734375, 447.819580078125, 73.0, 22.0 ],
					"text" : "select 13 10"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 649.052734375, 352.152923583984375, 56.0, 22.0 ],
					"text" : "metro 33"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 649.052734375, 311.486236572265625, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-74",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "int", "" ],
					"patching_rect" : [ 649.052734375, 391.819580078125, 77.0, 22.0 ],
					"text" : "serial d 9600"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 649.052734375, 996.1529541015625, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 12.0,
					"id" : "obj-6",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "int" ],
					"patching_rect" : [ 694.052734375, 900.1529541015625, 62.0, 22.0 ],
					"text" : "trigger b i"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-9",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 649.052734375, 823.1529541015625, 52.0, 23.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-22",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 694.052734375, 860.6529541015625, 52.0, 23.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Arial",
					"fontsize" : 13.0,
					"id" : "obj-42",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 649.052734375, 959.1529541015625, 130.0, 23.0 ],
					"text" : "if $i1 > $i2 then bang"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-59",
					"maxclass" : "ezdac~",
					"numinlets" : 2,
					"numoutlets" : 0,
					"patching_rect" : [ 650.052734375, 1189.4862060546875, 45.0, 45.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-22", 0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-59", 0 ],
					"source" : [ "obj-103", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-74", 0 ],
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-103", 0 ],
					"source" : [ "obj-110", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"source" : [ "obj-12", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-73", 0 ],
					"source" : [ "obj-12", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-1", 0 ],
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-90", 0 ],
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-82", 0 ],
					"source" : [ "obj-21", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-6", 0 ],
					"midpoints" : [ 703.552734375, 896.1529541015625, 703.552734375, 896.1529541015625 ],
					"source" : [ "obj-22", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-23", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-83", 0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"source" : [ "obj-25", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-21", 0 ],
					"source" : [ "obj-3", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-71", 0 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"source" : [ "obj-42", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 1 ],
					"midpoints" : [ 746.552734375, 944.1529541015625, 769.552734375, 944.1529541015625 ],
					"source" : [ "obj-6", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"midpoints" : [ 703.552734375, 944.1529541015625, 658.552734375, 944.1529541015625 ],
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-74", 0 ],
					"source" : [ "obj-70", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"source" : [ "obj-71", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"source" : [ "obj-72", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"source" : [ "obj-73", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"source" : [ "obj-74", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-2", 0 ],
					"source" : [ "obj-75", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-110", 0 ],
					"source" : [ "obj-8", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 1 ],
					"midpoints" : [ 1074.83343505859375, 830.99993896484375, 1097.83343505859375, 830.99993896484375 ],
					"source" : [ "obj-80", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"midpoints" : [ 1031.83343505859375, 830.99993896484375, 986.83343505859375, 830.99993896484375 ],
					"source" : [ "obj-80", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"midpoints" : [ 948.166748046875, 737.99993896484375, 986.83343505859375, 737.99993896484375 ],
					"source" : [ "obj-82", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-80", 0 ],
					"midpoints" : [ 1031.83343505859375, 782.99993896484375, 1031.83343505859375, 782.99993896484375 ],
					"source" : [ "obj-83", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-75", 0 ],
					"source" : [ "obj-84", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-42", 0 ],
					"midpoints" : [ 658.552734375, 851.1529541015625, 658.552734375, 851.1529541015625 ],
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-88", 0 ],
					"source" : [ "obj-90", 0 ]
				}

			}
 ],
		"dependency_cache" : [ 			{
				"name" : "senita-8ch.wav",
				"bootpath" : "C74:/media/msp",
				"type" : "WAVE",
				"implicit" : 1
			}
, 			{
				"name" : "rainstick.aif",
				"bootpath" : "C74:/media/msp",
				"type" : "AIFF",
				"implicit" : 1
			}
 ],
		"autosave" : 0
	}

}
