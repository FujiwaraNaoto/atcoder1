import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.Container;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Dimension;
import java.awt.event.*;

class SwingActionTest extends JFrame implements ActionListener {
  JLabel label;
  JButton button1;
  JButton button2;

  public static void main(String args[]) {
    SwingActionTest test = new SwingActionTest("SwingActionTest");
    test.setVisible(true);
  }

  SwingActionTest(String title) {
    setTitle(title);
    setBounds( 100, 100, 300, 200);
	  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    	
    setLayout(new FlowLayout());
    	
    JPanel panel = new JPanel();
    panel.setPreferredSize(new Dimension(200, 100));
    panel.setLayout(new FlowLayout());
    	
	  label = new JLabel("");

    button1 = new JButton("Up");
    button1.setPreferredSize(new Dimension(80, 40));
	  button1.addActionListener(this);
	  button2 = new JButton("Down");
    button2.setPreferredSize(new Dimension(80, 40));
	  button2.addActionListener(this);
    	
    panel.add(button1, BorderLayout.NORTH);
    panel.add(button2, BorderLayout.NORTH);
    panel.add(label, BorderLayout.SOUTH);
    	
    getContentPane().add(panel, BorderLayout.CENTER);
  }

  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == button1) {
    	label.setText("Up Clicked!");
    } else {
    	label.setText("Down Clicked!");
    }
  }
}