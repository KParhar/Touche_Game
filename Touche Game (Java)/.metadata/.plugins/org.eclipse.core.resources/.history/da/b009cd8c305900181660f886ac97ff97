package system.main.GUI;

import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.filechooser.FileNameExtensionFilter;

import system.main.navigation.Schematic;

public class GUI extends JFrame{
	
	public static final String TITLE = "Guidance System";
	
	public static final int WIDTH = 800, HEIGHT = 600;
	
	JButton openSchematicLoad;
	JFileChooser schematicLoad;
	File schematicFile;
	
	SchematicPanel schemPanel;
	Schematic schematic;
	
	public GUI()
	{
		super(TITLE);
		this.setSize(WIDTH, HEIGHT);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		GridBagLayout layout = new GridBagLayout();
	    this.setLayout(layout);
	    this.setResizable(false);
	    this.setLocationRelativeTo(null);
	    
	    schematicFile = null;
	    
	    schematic = null;
	    
	    schemPanel = new SchematicPanel();
	    schemPanel.addMouseListener(new MouseListener() {
	    	
			public void mouseClicked(MouseEvent e) {
				if(schematic != null) {
					if(e.getButton() == MouseEvent.BUTTON1) {
						schematic.setStartPos(e.getX()/schemPanel.getTileWidth(), e.getY()/schemPanel.getTileHeight());
						schemPanel.repaint();
					} else if(e.getButton() == MouseEvent.BUTTON3) {
						schematic.setEndPos(e.getX()/schemPanel.getTileWidth(), e.getY()/schemPanel.getTileHeight());
						schemPanel.repaint();
					}
				}
			}

			public void mouseEntered(MouseEvent arg0) {}
			public void mouseExited(MouseEvent arg0) {}
			public void mousePressed(MouseEvent arg0) {}
			public void mouseReleased(MouseEvent arg0) {}	    	
	    });
	    
	    schematicLoad = new JFileChooser();
	    schematicLoad.addChoosableFileFilter(new FileNameExtensionFilter("Image files", ImageIO.getReaderFileSuffixes()));
	    schematicLoad.setAcceptAllFileFilterUsed(false);
	    //Temp location
	    //schematicLoad.setCurrentDirectory(new File("C:/Users/Kush/Desktop/Guidance System Project"));
	    
	    openSchematicLoad = new JButton();
	    openSchematicLoad.setText("Load Schematic");
	    openSchematicLoad.addActionListener(new ActionListener() {
	    	public void actionPerformed(ActionEvent arg0) {
				loadSchematicFile();
			}
	    });
	    
	    GridBagConstraints c = new GridBagConstraints();
	    c.fill = GridBagConstraints.BOTH;
	    c.weighty = 1.0;
	    c.weightx = 1.0;
	    c.gridx = 0;
	    c.gridy = 0;
	    this.add(schemPanel, c);
	    
	    c.fill = GridBagConstraints.NONE;
	    c.weightx = 0.2;
	    c.weighty = 0.2;
	    c.gridx = 1;
	    c.gridy = 0;
	    this.add(openSchematicLoad, c);

	    this.setVisible(true);
	}
	
	void startDriving() {
		
	}
	
	void loadSchematicFile() {
		int returnVal = schematicLoad.showOpenDialog(GUI.this);
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            File file = schematicLoad.getSelectedFile();
            System.out.println("Opening: " + file.getName() + ".");
            BufferedImage schematicImg = null;
            try {
            	schematicImg = ImageIO.read(file);
			} catch (IOException e) {
				e.printStackTrace();
			}
            schematic = new Schematic(schematicImg, schemPanel);
            schemPanel.setSchem(schematic);
            schemPanel.repaint();
        }
	}
	
}
